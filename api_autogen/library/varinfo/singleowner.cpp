static var_info _cm_vtab_singleowner[] = {
	// VARTYPE   DATATYPE		NAME								LABEL										UNITS		META	GROUP			REQUIRED_IF						CONSTRAINTS						UI_HINTS{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"analysis_period", 	"Analyis period", 	"years", 	"", 	"Financial Parameters", 	"?=30", 	"INTEGER,MIN=0,MAX=50", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"federal_tax_rate", 	"Federal income tax rate", 	"%", 	"", 	"Financial Parameters", 	"*", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"state_tax_rate", 	"State income tax rate", 	"%", 	"", 	"Financial Parameters", 	"*", 	"", 	""},
"{ 	SSCINOUT, 	SSC_ARRAY, 	"cf_federal_tax_frac", 	"Federal income tax rate", 	"frac", 	"", 	"", 	"*", 	"LENGTH_EQUAL=cf_length", 	""},
"{ 	SSCINOUT, 	SSC_ARRAY, 	"cf_state_tax_frac", 	"State income tax rate", 	"frac", 	"", 	"", 	"*", 	"LENGTH_EQUAL=cf_length", 	""},
"{ 	SSCINOUT, 	SSC_ARRAY, 	"cf_effective_tax_frac", 	"Effective income tax rate", 	"frac", 	"", 	"", 	"*", 	"LENGTH_EQUAL=cf_length", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"property_tax_rate", 	"Property tax rate", 	"%", 	"", 	"Financial Parameters", 	"?=0.0", 	"MIN=0,MAX=100", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"prop_tax_cost_assessed_percent", 	"Percent of pre-financing costs assessed", 	"%", 	"", 	"Financial Parameters", 	"?=95", 	"MIN=0,MAX=100", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"prop_tax_assessed_decline", 	"Assessed value annual decline", 	"%", 	"", 	"Financial Parameters", 	"?=5", 	"MIN=0,MAX=100", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"real_discount_rate", 	"Real discount rate", 	"%", 	"", 	"Financial Parameters", 	"*", 	"MIN=-99", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"inflation_rate", 	"Inflation rate", 	"%", 	"", 	"Financial Parameters", 	"*", 	"MIN=-99", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"insurance_rate", 	"Insurance rate", 	"%", 	"", 	"Financial Parameters", 	"?=0.0", 	"MIN=0,MAX=100", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"system_capacity", 	"System nameplate capacity", 	"kW", 	"", 	"Power CycleCommon", 	"*", 	"POSITIVE", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"system_heat_rate", 	"System heat rate", 	"MMBTus/MWh", 	"", 	"", 	"?=0.0", 	"MIN=0", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_fixed", 	"Fixed O&M annual amount", 	"$/year", 	"", 	"System Costs", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"om_fixed_escal", 	"Fixed O&M escalation", 	"%/year", 	"", 	"System Costs", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_production", 	"Production-based O&M amount", 	"$/MWh", 	"", 	"System Costs", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"om_production_escal", 	"Production-based O&M escalation", 	"%/year", 	"", 	"System Costs", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_capacity", 	"Capacity-based O&M amount", 	"$/kWcap", 	"", 	"System Costs", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"om_capacity_escal", 	"Capacity-based O&M escalation", 	"%/year", 	"", 	"System Costs", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_fuel_cost", 	"Fuel cost", 	"$/MMBtu", 	"", 	"System Costs", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"om_fuel_cost_escal", 	"Fuel cost escalation", 	"%/year", 	"", 	"System Costs", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"annual_fuel_usage", 	"Fuel usage", 	"kWht", 	"", 	"", 	"?=0", 	"MIN=0", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_replacement_cost1", 	"Repacement cost 1", 	"$/kWh", 	"", 	"System Costs", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_replacement_cost2", 	"Repacement cost 2", 	"$/kW", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"om_replacement_cost_escal", 	"Replacement cost escalation", 	"%/year", 	"", 	"System Costs", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"om_opt_fuel_1_usage", 	"Biomass feedstock usage", 	"unit", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_opt_fuel_1_cost", 	"Biomass feedstock cost", 	"$/unit", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"om_opt_fuel_1_cost_escal", 	"Biomass feedstock cost escalation", 	"%/year", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"om_opt_fuel_2_usage", 	"Coal feedstock usage", 	"unit", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_opt_fuel_2_cost", 	"Coal feedstock cost", 	"$/unit", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"om_opt_fuel_2_cost_escal", 	"Coal feedstock cost escalation", 	"%/year", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"add_om_num_types", 	"Number of O and M types", 	"", 	"", 	"", 	"?=0", 	"INTEGER,MIN=0,MAX=2", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"om_capacity1_nameplate", 	"Battery capacity for O&M values", 	"kW", 	"", 	"", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_production1_values", 	"Battery production for O&M values", 	"kWh", 	"", 	"", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_fixed1", 	"Battery fixed O&M annual amount", 	"$/year", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_production1", 	"Battery production-based O&M amount", 	"$/MWh", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_capacity1", 	"Battery capacity-based O&M amount", 	"$/kWcap", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"om_capacity2_nameplate", 	"Fuel cell capacity for O&M values", 	"kW", 	"", 	"", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_production2_values", 	"Fuel cell production for O&M values", 	"kWh", 	"", 	"", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_fixed2", 	"Fuel cell fixed O&M annual amount", 	"$/year", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_production2", 	"Fuel cell production-based O&M amount", 	"$/MWh", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"om_capacity2", 	"Fuel cell capacity-based O&M amount", 	"$/kWcap", 	"", 	"", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_fed_amount", 	"Federal amount-based ITC amount", 	"$", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_fed_amount_deprbas_fed", 	"Federal amount-based ITC reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_fed_amount_deprbas_sta", 	"Federal amount-based ITC reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_sta_amount", 	"State amount-based ITC amount", 	"$", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_sta_amount_deprbas_fed", 	"State amount-based ITC reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_sta_amount_deprbas_sta", 	"State amount-based ITC reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_fed_percent", 	"Federal percentage-based ITC percent", 	"%", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_fed_percent_maxvalue", 	"Federal percentage-based ITC maximum value", 	"$", 	"", 	"Incentives", 	"?=1e99", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_fed_percent_deprbas_fed", 	"Federal percentage-based ITC reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_fed_percent_deprbas_sta", 	"Federal percentage-based ITC reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_sta_percent", 	"State percentage-based ITC percent", 	"%", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_sta_percent_maxvalue", 	"State percentage-based ITC maximum Value", 	"$", 	"", 	"Incentives", 	"?=1e99", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_sta_percent_deprbas_fed", 	"State percentage-based ITC reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"itc_sta_percent_deprbas_sta", 	"State percentage-based ITC reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"ptc_fed_amount", 	"Federal PTC amount", 	"$/kWh", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ptc_fed_term", 	"Federal PTC term", 	"years", 	"", 	"Incentives", 	"?=10", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ptc_fed_escal", 	"Federal PTC escalation", 	"%/year", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"ptc_sta_amount", 	"State PTC amount", 	"$/kWh", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ptc_sta_term", 	"State PTC term", 	"years", 	"", 	"Incentives", 	"?=10", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ptc_sta_escal", 	"State PTC escalation", 	"%/year", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_fed_amount", 	"Federal amount-based IBI amount", 	"$", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_fed_amount_tax_fed", 	"Federal amount-based IBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_fed_amount_tax_sta", 	"Federal amount-based IBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_fed_amount_deprbas_fed", 	"Federal amount-based IBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_fed_amount_deprbas_sta", 	"Federal amount-based IBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_sta_amount", 	"State amount-based IBI amount", 	"$", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_sta_amount_tax_fed", 	"State amount-based IBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_sta_amount_tax_sta", 	"State amount-based IBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_sta_amount_deprbas_fed", 	"State amount-based IBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_sta_amount_deprbas_sta", 	"State amount-based IBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_uti_amount", 	"Utility amount-based IBI amount", 	"$", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_uti_amount_tax_fed", 	"Utility amount-based IBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_uti_amount_tax_sta", 	"Utility amount-based IBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_uti_amount_deprbas_fed", 	"Utility amount-based IBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_uti_amount_deprbas_sta", 	"Utility amount-based IBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_oth_amount", 	"Other amount-based IBI amount", 	"$", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_oth_amount_tax_fed", 	"Other amount-based IBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_oth_amount_tax_sta", 	"Other amount-based IBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_oth_amount_deprbas_fed", 	"Other amount-based IBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_oth_amount_deprbas_sta", 	"Other amount-based IBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_fed_percent", 	"Federal percentage-based IBI percent", 	"%", 	"", 	"Incentives", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_fed_percent_maxvalue", 	"Federal percentage-based IBI maximum value", 	"$", 	"", 	"Incentives", 	"?=1e99", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_fed_percent_tax_fed", 	"Federal percentage-based IBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_fed_percent_tax_sta", 	"Federal percentage-based IBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_fed_percent_deprbas_fed", 	"Federal percentage-based IBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_fed_percent_deprbas_sta", 	"Federal percentage-based IBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_sta_percent", 	"State percentage-based IBI percent", 	"%", 	"", 	"Incentives", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_sta_percent_maxvalue", 	"State percentage-based IBI maximum value", 	"$", 	"", 	"Incentives", 	"?=1e99", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_sta_percent_tax_fed", 	"State percentage-based IBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_sta_percent_tax_sta", 	"State percentage-based IBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_sta_percent_deprbas_fed", 	"State percentage-based IBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_sta_percent_deprbas_sta", 	"State percentage-based IBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_uti_percent", 	"Utility percentage-based IBI percent", 	"%", 	"", 	"Incentives", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_uti_percent_maxvalue", 	"Utility percentage-based IBI maximum value", 	"$", 	"", 	"Incentives", 	"?=1e99", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_uti_percent_tax_fed", 	"Utility percentage-based IBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_uti_percent_tax_sta", 	"Utility percentage-based IBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_uti_percent_deprbas_fed", 	"Utility percentage-based IBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_uti_percent_deprbas_sta", 	"Utility percentage-based IBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_oth_percent", 	"Other percentage-based IBI percent", 	"%", 	"", 	"Incentives", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_oth_percent_maxvalue", 	"Other percentage-based IBI maximum value", 	"$", 	"", 	"Incentives", 	"?=1e99", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_oth_percent_tax_fed", 	"Other percentage-based IBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_oth_percent_tax_sta", 	"Other percentage-based IBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_oth_percent_deprbas_fed", 	"Other percentage-based IBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"ibi_oth_percent_deprbas_sta", 	"Other percentage-based IBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_fed_amount", 	"Federal CBI amount", 	"$/Watt", 	"", 	"Incentives", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_fed_maxvalue", 	"Federal CBI maximum", 	"$", 	"", 	"Incentives", 	"?=1e99", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_fed_tax_fed", 	"Federal CBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_fed_tax_sta", 	"Federal CBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_fed_deprbas_fed", 	"Federal CBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_fed_deprbas_sta", 	"Federal CBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_sta_amount", 	"State CBI amount", 	"$/Watt", 	"", 	"Incentives", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_sta_maxvalue", 	"State CBI maximum", 	"$", 	"", 	"Incentives", 	"?=1e99", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_sta_tax_fed", 	"State CBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_sta_tax_sta", 	"State CBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_sta_deprbas_fed", 	"State CBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_sta_deprbas_sta", 	"State CBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_uti_amount", 	"Utility CBI amount", 	"$/Watt", 	"", 	"Incentives", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_uti_maxvalue", 	"Utility CBI maximum", 	"$", 	"", 	"Incentives", 	"?=1e99", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_uti_tax_fed", 	"Utility CBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_uti_tax_sta", 	"Utility CBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_uti_deprbas_fed", 	"Utility CBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_uti_deprbas_sta", 	"Utility CBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_oth_amount", 	"Other CBI amount", 	"$/Watt", 	"", 	"Incentives", 	"?=0.0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_oth_maxvalue", 	"Other CBI maximum", 	"$", 	"", 	"Incentives", 	"?=1e99", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_oth_tax_fed", 	"Other CBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_oth_tax_sta", 	"Other CBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_oth_deprbas_fed", 	"Other CBI reduces federal depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"cbi_oth_deprbas_sta", 	"Other CBI reduces state depreciation basis", 	"0/1", 	"", 	"Incentives", 	"?=0", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"pbi_fed_amount", 	"Federal PBI amount", 	"$/kWh", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"pbi_fed_term", 	"Federal PBI term", 	"years", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"pbi_fed_escal", 	"Federal PBI escalation", 	"%", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"pbi_fed_tax_fed", 	"Federal PBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"pbi_fed_tax_sta", 	"Federal PBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"pbi_sta_amount", 	"State PBI amount", 	"$/kWh", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"pbi_sta_term", 	"State PBI term", 	"years", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"pbi_sta_escal", 	"State PBI escalation", 	"%", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"pbi_sta_tax_fed", 	"State PBI federal taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"pbi_sta_tax_sta", 	"State PBI state taxable", 	"0/1", 	"", 	"Incentives", 	"?=1", 	"BOOLEAN", 	""},
"{ 	SSC_OUTPUT, 	SSC_ARRAY, 	"pbi_uti_amount", 	"Utility PBI amount", 	"$/kWh", 	"", 	"Incentives", 	"?=0", 	"", 	""},
"{ 	SSC_OUTPUT, 	SSC_NUMBER, 	"pbi_uti_term", 	"Utility PBI term", 	"yea