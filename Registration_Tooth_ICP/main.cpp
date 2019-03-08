#include "STLINFO.h"
#include "load_and_split_stl_format.h"
#include "calc_average_xyz.h"
#include "calc_covariance_matrix.h"
#include "calc_eigendecompostion.h"
#include "initial_registration.h"
#include "stl_add_and_save.h"
#include "calc_closest_point.h"

int main() {

	STLINFO info_jaw1, info_jaw2;
	load_and_split_stl_format("jaw1.stl", info_jaw1);
	load_and_split_stl_format("jaw2.stl", info_jaw2);

	stl_add_and_save("add_original_jaw1_jaw2.stl", info_jaw1, info_jaw2);

	//PCA
	calc_average_xyz(info_jaw1);
	calc_average_xyz(info_jaw2);
	Matrix3f mat_covariance1, mat_covariance2;
	calc_covariance_matrix(info_jaw1, mat_covariance1);
	calc_covariance_matrix(info_jaw2, mat_covariance2);

	Matrix3f vec_eigen1, vec_eigen2;
	Vector3f value_eigen1, value_eigen2;
	calc_eigendecomposition(mat_covariance1, mat_covariance2, vec_eigen1, vec_eigen2, value_eigen1, value_eigen2);
	cout << value_eigen1 << "\n";

	initial_registration(info_jaw1, info_jaw2, vec_eigen1, vec_eigen2);

	vector<pair<XYZ, XYZ>> pair_closest_point;
	calc_closest_point(info_jaw1, info_jaw2, pair_closest_point);



	return 0;
}