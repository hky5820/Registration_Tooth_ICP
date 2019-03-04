#pragma once
#include <Eigen/Dense>

using namespace Eigen;

void calc_eigendecomposition(Matrix3f &mat_convariance1, Matrix3f &mat_convariance2, Matrix3f &vec_eigen1, Matrix3f &vec_eigen2, Vector3f &value_eigen1, Vector3f &value_eigen2);