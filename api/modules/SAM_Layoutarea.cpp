#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <iostream>

#include <ssc/sscapi.h>

#include "SAM_api.h"
#include "ErrorHandler.h"
#include "SAM_Layoutarea.h"

SAM_EXPORT SAM_Layoutarea SAM_Layoutarea_construct(const char* def, SAM_error* err){
	SAM_Layoutarea result = nullptr;
	translateExceptions(err, [&]{
		result = ssc_data_create();
	});
	return result;
}

SAM_EXPORT int SAM_Layoutarea_execute(SAM_Layoutarea data, int verbosity, SAM_error* err){
	int n_err = 0;
	translateExceptions(err, [&]{
		n_err += SAM_module_exec("layoutarea", data, verbosity, err);
	});
	return n_err;
}


SAM_EXPORT void SAM_Layoutarea_destruct(SAM_Layoutarea system)
{
	ssc_data_free(system);
}

SAM_EXPORT void SAM_Layoutarea_Common_positions_mset(SAM_Layoutarea ptr, double* mat, int nrows, int ncols, SAM_error *err){
	translateExceptions(err, [&]{
		ssc_data_set_matrix(ptr, "positions", mat, nrows, ncols);
	});
}

SAM_EXPORT double* SAM_Layoutarea_Common_positions_mget(SAM_Layoutarea ptr, int* nrows, int* ncols, SAM_error *err){
	double* result = nullptr;
	translateExceptions(err, [&]{
	result = ssc_data_get_matrix(ptr, "positions", nrows, ncols);
	if (!result)
		make_access_error("SAM_Layoutarea", "positions");
	});
	return result;
}



SAM_EXPORT double SAM_Layoutarea_Outputs_area_nget(SAM_Layoutarea ptr, SAM_error *err){
	double result;
	translateExceptions(err, [&]{
	if (!ssc_data_get_number(ptr, "area", &result))
		make_access_error("SAM_Layoutarea", "area");
	});
	return result;
}



SAM_EXPORT double* SAM_Layoutarea_Outputs_convex_hull_mget(SAM_Layoutarea ptr, int* nrows, int* ncols, SAM_error *err){
	double* result = nullptr;
	translateExceptions(err, [&]{
	result = ssc_data_get_matrix(ptr, "convex_hull", nrows, ncols);
	if (!result)
		make_access_error("SAM_Layoutarea", "convex_hull");
	});
	return result;
}


