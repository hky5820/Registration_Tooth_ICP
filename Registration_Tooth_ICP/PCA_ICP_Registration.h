#pragma once
#include "STLINFO.h"
#include "load_and_split_stl_format.h"
#include "calc_average_xyz.h"
#include "calc_covariance_matrix.h"
#include "calc_eigendecompostion.h"
#include "initial_registration.h"
#include "stl_add_and_save.h"
#include "calc_closest_point.h"
#include "calc_alignment.h"
#include "apply_alignment.h"
#include "stl_add_and_save.h"
#include "calc_metric.h"

void PCA_ICP_Registration(const char* name1, const char* name2, const char *name_result);