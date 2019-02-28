#include "STLINFO.h"
#include "load_and_split_stl_format.h"
#include "calc_average_xyz.h"
#include "calc_covariance_matrix.h"

int main() {

	STLINFO info_jaw1, info_jaw2;
	load_and_split_stl_format("jaw1.stl", info_jaw1);
	load_and_split_stl_format("jaw2.stl", info_jaw2);

	calc_average_xyz(info_jaw1);
	calc_average_xyz(info_jaw2);

	Matrix3f mat_covariance1, mat_covariance2;
	calc_covariance_matrix(info_jaw1, mat_covariance1);
	calc_covariance_matrix(info_jaw2, mat_covariance2);

	return 0;
}