#pragma once
#include <Eigen/Dense>
#include <vector>
#include <cmath>
#include "STLINFO.h"

const float M_PI = (float)3.14159265358979323846;

using namespace Eigen;
using namespace std;

void calc_mat_rotation(Matrix3f &vec_eigen1, Matrix3f &vec_eigen2, Matrix3f &result_mat_rotation1, Matrix3f &result_mat_rotation2, Matrix3f &result_mat_rotation3, Matrix3f &result_mat_rotation4);