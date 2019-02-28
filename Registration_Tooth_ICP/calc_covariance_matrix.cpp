#include "calc_covariance_matrix.h"

float calc_matrix_element(vector<float> &param1, vector<float> &param2, int num_of_triangle, float avg1, float avg2) {

	float value_matrix_elemnent;
	float sum = 0;

	for (int i = 0; i < num_of_triangle * 3; i++) {
		sum += (param1[i] - avg1) * (param2[i] - avg2);
	}

	return value_matrix_elemnent = sum / (num_of_triangle * 3);
}

void calc_covariance_matrix(STLINFO & info_jaw, Matrix3f &result)
{
	float mat_result_xx, mat_result_yy, mat_result_zz;
	float mat_result_xy, mat_result_xz, mat_result_yz;
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
	mat_result_xx = calc_matrix_element(info_jaw.X, info_jaw.X, info_jaw.num_of_triangle, info_jaw.average_xyz.x, info_jaw.average_xyz.x);
	mat_result_yy = calc_matrix_element(info_jaw.Y, info_jaw.Y, info_jaw.num_of_triangle, info_jaw.average_xyz.y, info_jaw.average_xyz.y);
	mat_result_zz = calc_matrix_element(info_jaw.Z, info_jaw.Z, info_jaw.num_of_triangle, info_jaw.average_xyz.z, info_jaw.average_xyz.z);

	mat_result_xy = calc_matrix_element(info_jaw.X, info_jaw.Y, info_jaw.num_of_triangle, info_jaw.average_xyz.x, info_jaw.average_xyz.y);
	mat_result_xz = calc_matrix_element(info_jaw.X, info_jaw.Z, info_jaw.num_of_triangle, info_jaw.average_xyz.x, info_jaw.average_xyz.z);
	mat_result_yz = calc_matrix_element(info_jaw.Y, info_jaw.Z, info_jaw.num_of_triangle, info_jaw.average_xyz.y, info_jaw.average_xyz.z);

	cout << "mat_result_xx = " << mat_result_xx << "\n";
	cout << "mat_result_yy = " << mat_result_yy << "\n";
	cout << "mat_result_zz = " << mat_result_zz << "\n";
	result(0, 0) = mat_result_xx; result(0, 1) = mat_result_xy; result(0, 2) = mat_result_xz;
	result(1, 0) = mat_result_xy; result(1, 1) = mat_result_yy; result(1, 2) = mat_result_yz;
	result(2, 0) = mat_result_xz; result(2, 1) = mat_result_yz; result(2, 2) = mat_result_zz;
}