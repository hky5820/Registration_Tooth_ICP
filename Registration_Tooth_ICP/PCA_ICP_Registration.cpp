#include "PCA_ICP_Registration.h"

void PCA_ICP_Registration(const char* name1, const char* name2, const char *name_result) {
	
	STLINFO info_jaw1, info_jaw2;
	load_and_split_stl_format(name1, info_jaw1);
	load_and_split_stl_format(name2, info_jaw2);
	//stl_add_and_save("add_original_jaw1_jaw2.stl", info_jaw1, info_jaw2);


	//PCA start
	calc_average_xyz(info_jaw1); 
	calc_average_xyz(info_jaw2);
	Matrix3f mat_covariance1, mat_covariance2;
	calc_covariance_matrix(info_jaw1, mat_covariance1);
	calc_covariance_matrix(info_jaw2, mat_covariance2);
	Matrix3f vec_eigen1, vec_eigen2;
	Vector3f value_eigen1, value_eigen2;
	calc_eigendecomposition(mat_covariance1, mat_covariance2, vec_eigen1, vec_eigen2, value_eigen1, value_eigen2);
	initial_registration(info_jaw1, info_jaw2, vec_eigen1, vec_eigen2);
	stl_add_and_save("./Data_STL/result_init_registration_translation_applied.stl", info_jaw1, info_jaw2);
	//PCA end


	//ICP start
	Matrix4f mat_result_of_alignment;
	vector<pair<XYZ, XYZ>> pair_closest_point;
	//float metric;
	//for (int i = 0; i < 50; i++) {
	//	cout << "ICP " << i << " ";
	//	mat_result_of_alignment = Matrix4f::Identity(4, 4);
	//	calc_closest_point(info_jaw1, info_jaw2, pair_closest_point);
	//	calc_alignment(pair_closest_point, mat_result_of_alignment);
	//	metric = calc_metric(pair_closest_point, mat_result_of_alignment);
	//	cout << "metric : " << metric << "\n";
	//	apply_alignment(info_jaw1, mat_result_of_alignment);
	//	pair_closest_point.clear();
	//}
	////ICP end

	float metric_cur = pow(10, 7) - 10000;
	float metric_pre = pow(10, 7);
	int cnt = 1;
	while( (metric_pre - metric_cur) > 1000){
		cout << "ICP " << cnt++ << "\n";
		metric_pre = metric_cur;
		mat_result_of_alignment = Matrix4f::Identity(4, 4);
		calc_closest_point(info_jaw1, info_jaw2, pair_closest_point);
		calc_alignment(pair_closest_point, mat_result_of_alignment);
		metric_cur = calc_metric(pair_closest_point, mat_result_of_alignment);
		apply_alignment(info_jaw1, mat_result_of_alignment);
		pair_closest_point.clear();
	}

	stl_add_and_save(name_result, info_jaw1, info_jaw2);
}