#pragma once
#include "applying_rotation.h"
#include "calc_mat_rotation.h"
#include "stl_add_and_save.h"
#include "translation_to_origin.h"

void initial_registration(STLINFO & info_jaw1, STLINFO & info_jaw2, Matrix3f & vec_eigen1, Matrix3f & vec_eigen2);