#include "core.h"
#include "lib_financial.h"
#include "common_financial.h"
#include <sstream>
using namespace libfin;

static var_info vtab_thirdpartyownership[] = {
/*   VARTYPE           DATATYPE          NAME                        LABEL                                  UNITS         META                      GROUP            REQUIRED_IF                 CONSTRAINTS                      UI_HINTS*/

	{ SSC_INPUT, SSC_NUMBER, "analysis_period", "Analyis period", "years", "", "Financials", "?=30", "INTEGER,MIN=0,MAX=50", "" },
	{ SSC_INPUT, SSC_NUMBER, "real_discount_rate", "Real discount rate", "%", "", "Financials", "*", "MIN=-99", "" },
	{ SSC_INPUT, SSC_NUMBER, "inflation_rate", "Inflation rate", "%", "", "Financials", "*", "MIN=-99", "" },

	{ SSC_INPUT, SSC_NUMBER, "lease_or_ppa", "Lease or PPA agreement", "0/1", "0=lease,1=ppa", "thirdpartyownership", "?=0", "INTEGER,MIN=0,MAX=1", "" },
	
	{ SSC_INPUT,        SSC_ARRAY,       "annual_energy_value",             "Energy value",                       "$",            "",                      "thirdpartyownership",      "*",                       "",                                         "" },
	{ SSC_INPUT, SSC_ARRAY, "gen", "Power generated by renewable resource", "kW", "", "", "*", "", "" },


	{ SSC_INPUT, SSC_ARRAY, "degradation", "Annual degradation", "%", "", "AnnualOutput", "*", "", "" },
	{ SSC_INPUT, SSC_NUMBER, "system_use_lifetime_output", "Lifetime hourly system outputs", "0/1", "0=hourly first year,1=hourly lifetime", "AnnualOutput", "*", "INTEGER,MIN=0", "" },

	{ SSC_INPUT, SSC_NUMBER, "lease_price", "Monthly lease price", "$/month", "", "Cash Flow", "lease_or_ppa=0", "", "" },
	{ SSC_INPUT, SSC_NUMBER, "lease_escalation", "Monthly lease escalation", "%/year", "", "Cash Flow", "lease_or_ppa=0", "", "" },

	{ SSC_INPUT, SSC_NUMBER, "ppa_price", "Monthly lease price", "$/month", "", "Cash Flow", "lease_or_ppa=1", "", "" },
	{ SSC_INPUT, SSC_NUMBER, "ppa_escalation", "Monthly lease escalation", "%/year", "", "Cash Flow", "lease_or_ppa=1", "", "" },




	/* financial outputs */
	{ SSC_OUTPUT,        SSC_NUMBER,     "cf_length",                "Number of periods in cash flow",      "",             "",                      "Cash Flow",      "*",                       "INTEGER",                                  "" },

	//{ SSC_OUTPUT,        SSC_NUMBER,     "lcoe_real",                "Real LCOE",                          "cents/kWh",    "",                      "Cash Flow",      "*",                       "",                                         "" },
	//{ SSC_OUTPUT,        SSC_NUMBER,     "lcoe_nom",                 "Nominal LCOE",                       "cents/kWh",    "",                      "Cash Flow",      "*",                       "",                                         "" },
	{ SSC_OUTPUT,        SSC_NUMBER,     "npv",                      "Net present value",				   "$",            "",                      "Cash Flow",      "*",                       "",                                         "" },

	{ SSC_OUTPUT,        SSC_ARRAY,      "cf_energy_net",      "Energy",                  "kWh",            "",                      "Cash Flow",      "*",                     "LENGTH_EQUAL=cf_length",                "" },
//	{ SSC_OUTPUT,        SSC_ARRAY,      "cf_energy_value",      "Value of electricity savings",                  "$",            "",                      "Cash Flow",      "*",                     "LENGTH_EQUAL=cf_length",                "" },

	{ SSC_OUTPUT,        SSC_ARRAY,      "cf_agreement_cost",      "Agreement cost",                  "$",            "",                      "Cash Flow",      "*",                     "LENGTH_EQUAL=cf_length",                "" },

	{ SSC_OUTPUT,        SSC_ARRAY,      "cf_after_tax_net_equity_cost_flow",        "After-tax annual costs",           "$",            "",                      "Cash Flow",      "*",                     "LENGTH_EQUAL=cf_length",                "" },
	{ SSC_OUTPUT,        SSC_ARRAY,      "cf_after_tax_cash_flow",                   "After-tax cash flow",                      "$",            "",                      "Cash Flow",      "*",                     "LENGTH_EQUAL=cf_length",                "" },

	{ SSC_OUTPUT,        SSC_ARRAY,      "cf_payback_with_expenses",                 "Payback with expenses",                    "$",            "",                      "Cash Flow",      "*",                     "LENGTH_EQUAL=cf_length",                "" },
	{ SSC_OUTPUT,        SSC_ARRAY,      "cf_cumulative_payback_with_expenses",      "Cumulative payback with expenses",         "$",            "",                      "Cash Flow",      "*",                     "LENGTH_EQUAL=cf_length",                "" },
	



var_info_invalid };

extern var_info
	vtab_depreciation[];

enum {
	CF_degradation,
	CF_energy_net,
	CF_energy_value,
	CF_agreement_cost,

	CF_after_tax_net_equity_cost_flow,
	CF_after_tax_cash_flow,

	CF_payback_with_expenses,
	CF_cumulative_payback_with_expenses,
	

	CF_max };




class cm_thirdpartyownership : public compute_module
{
private:
	util::matrix_t<double> cf;
	hourly_energy_calculation hourly_energy_calcs;

public:
	cm_thirdpartyownership()
	{
		add_var_info( vtab_depreciation );
		add_var_info( vtab_thirdpartyownership );
	}

	void exec( ) throw( general_error )
	{
		int i;


		int nyears = as_integer("analysis_period");

		// initialize cashflow matrix
		cf.resize_fill( CF_max, nyears+1, 0.0 );

		// initialize energy and revenue
		size_t count = 0;
		ssc_number_t *arrp = 0;
		

		// degradation
		// degradation starts in year 2 for single value degradation - no degradation in year 1 - degradation =1.0
		// lifetime degradation applied in technology compute modules
		if (as_integer("system_use_lifetime_output") == 1)
		{
			for (i = 1; i <= nyears; i++) cf.at(CF_degradation, i) = 1.0;
		}
		else
		{
			size_t count_degrad = 0;
			ssc_number_t *degrad = 0;
			degrad = as_array("degradation", &count_degrad);

			if (count_degrad == 1)
			{
				for (i = 1; i <= nyears; i++) cf.at(CF_degradation, i) = pow((1.0 - degrad[0] / 100.0), i - 1);
			}
			else if (count_degrad > 0)
			{
				for (i = 0; i < nyears && i < (int)count_degrad; i++) cf.at(CF_degradation, i + 1) = (1.0 - degrad[i] / 100.0);
			}
		}

		// energy
		hourly_energy_calcs.calculate(this);

		if (as_integer("system_use_lifetime_output") == 0)
		{
			double first_year_energy = 0.0;
			for (int i = 0; i < 8760; i++)
				first_year_energy += hourly_energy_calcs.hourly_energy()[i];
			for (int y = 1; y <= nyears; y++)
				cf.at(CF_energy_net, y) = first_year_energy * cf.at(CF_degradation, y);
		}
		else
		{
			for (int y = 1; y <= nyears; y++)
			{
				cf.at(CF_energy_net, y) = 0;
				int i = 0;
				for (int m = 0; m<12; m++)
					for (int d = 0; d<util::nday[m]; d++)
						for (int h = 0; h<24; h++)
							if (i<8760)
							{
					cf.at(CF_energy_net, y) += hourly_energy_calcs.hourly_energy()[(y - 1) * 8760 + i] * cf.at(CF_degradation, y);
					i++;
							}
			}

		}
		// output from utility rate already nyears+1 - no offset
		arrp = as_array("annual_energy_value", &count);
		if (count != nyears+1)
			throw exec_error("third party ownership", util::format("energy value input wron length (%d) should be (%d)",count, nyears+1));
		for (i = 0; i < count; i++)
			cf.at(CF_energy_value, i) = (double) arrp[i];
		
	
		double inflation_rate = as_double("inflation_rate")*0.01;
		
		double real_discount_rate = as_double("real_discount_rate")*0.01;
		double nom_discount_rate = (1.0 + real_discount_rate) * (1.0 + inflation_rate) - 1.0;


		bool monthly_lease = (as_integer("lease_or_ppa") == 0);


		double annual_price = 0;
		double annual_esc = 0;
		if (monthly_lease)
		{
			annual_price = as_double("lease_price") *12.0;
			annual_esc = as_double("lease_escalation") / 100.0;
			for (int i = 1; i<=nyears; i++)
				cf.at(CF_agreement_cost, i) = annual_price * pow(1 + annual_esc, i-1 );
		}
		else
		{
			annual_price = as_double("ppa_price");
			annual_esc = as_double("ppa_escalation") / 100.0;
			for (int i = 1; i<=nyears; i++)
				cf.at(CF_agreement_cost, i) = annual_price * cf.at(CF_energy_net,i) * pow(1 + annual_esc, i-1);
		}



		

		for (i=1; i<=nyears; i++)
		{			

			cf.at(CF_after_tax_net_equity_cost_flow, i) =
				-cf.at(CF_agreement_cost, i);

			cf.at(CF_after_tax_cash_flow,i) = 
				cf.at(CF_after_tax_net_equity_cost_flow, i)
				+ cf.at(CF_energy_value, i);

			cf.at(CF_payback_with_expenses,i) =
					cf.at(CF_after_tax_cash_flow,i);


			cf.at(CF_cumulative_payback_with_expenses,i) = 
				cf.at(CF_cumulative_payback_with_expenses,i-1)
				+cf.at(CF_payback_with_expenses,i);
	
		}
		
		double npv_energy_real = npv( CF_energy_net, nyears, real_discount_rate );
		double lcoe_real = -( cf.at(CF_after_tax_net_equity_cost_flow,0) + npv(CF_after_tax_net_equity_cost_flow, nyears, nom_discount_rate) ) * 100;
		if (npv_energy_real == 0.0) 
		{
			lcoe_real = std::numeric_limits<double>::quiet_NaN();
		}
		else
		{
			lcoe_real /= npv_energy_real;
		}

		double npv_energy_nom = npv( CF_energy_net, nyears, nom_discount_rate );
		double lcoe_nom = -( cf.at(CF_after_tax_net_equity_cost_flow,0) + npv(CF_after_tax_net_equity_cost_flow, nyears, nom_discount_rate) ) * 100;
		if (npv_energy_nom == 0.0) 
		{
			lcoe_nom = std::numeric_limits<double>::quiet_NaN();
		}
		else
		{
			lcoe_nom /= npv_energy_nom;
		}

		double net_present_value = cf.at(CF_after_tax_cash_flow, 0) + npv(CF_after_tax_cash_flow, nyears, nom_discount_rate );

		assign( "cf_length", var_data( (ssc_number_t) nyears+1 ));

		//LCOE's commented out so as not to confuse the user. They don't compare to other LCOEs.
//		assign( "lcoe_real", var_data((ssc_number_t)lcoe_real) );
//		assign( "lcoe_nom", var_data((ssc_number_t)lcoe_nom) );
		assign( "npv",  var_data((ssc_number_t)net_present_value) );

		assign( "discount_nominal", var_data((ssc_number_t)(nom_discount_rate*100.0) ));		
		
		
		save_cf(CF_agreement_cost, nyears, "cf_agreement_cost");
		save_cf(CF_energy_net, nyears, "cf_energy_net");
//		save_cf(CF_energy_value, nyears, "cf_energy_value");


		save_cf( CF_after_tax_net_equity_cost_flow, nyears, "cf_after_tax_net_equity_cost_flow" );
		save_cf( CF_after_tax_cash_flow, nyears, "cf_after_tax_cash_flow" );

		save_cf( CF_payback_with_expenses, nyears, "cf_payback_with_expenses" );
		save_cf( CF_cumulative_payback_with_expenses, nyears, "cf_cumulative_payback_with_expenses" );
	

	}

/* These functions can be placed in common financial library with matrix and constants passed? */

	void save_cf(int cf_line, int nyears, const std::string &name)
	{
		ssc_number_t *arrp = allocate( name, nyears+1 );
		for (int i=0;i<=nyears;i++)
			arrp[i] = (ssc_number_t)cf.at(cf_line, i);
	}

	double npv( int cf_line, int nyears, double rate ) throw ( general_error )
	{		
		if (rate <= -1.0) throw general_error("cannot calculate NPV with discount rate less or equal to -1.0");

		double rr = 1/(1+rate);
		double result = 0;
		for (int i=nyears;i>0;i--)
			result = rr * result + cf.at(cf_line,i);

		return result*rr;
	}

	double min( double a, double b )
	{
		return (a < b) ? a : b;
	}

};

DEFINE_MODULE_ENTRY( thirdpartyownership, "Residential/Commercial 3rd Party Ownership Finance model.", 1 );