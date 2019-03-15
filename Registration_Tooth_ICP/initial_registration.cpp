#include "initial_registration.h"

void applying_rot(STLINFO &info_jaw, Matrix3f &mat) {

	for (unsigned int i = 0; i < info_jaw.num_of_triangle; i++) {
		Vector3f first, second, third;
		first = { info_jaw.triangle[i].first.x, info_jaw.triangle[i].first.y, info_jaw.triangle[i].first.z };
		second = { info_jaw.triangle[i].second.x,info_jaw.triangle[i].second.y,info_jaw.triangle[i].second.z };
		third = { info_jaw.triangle[i].third.x, info_jaw.triangle[i].third.y, info_jaw.triangle[i].third.z };

		Vector3f result_first, result_second, result_third;
		result_first = mat * first;
		result_second = mat * second;
		result_third = mat * third;

		info_jaw.triangle[i].first.x = result_first.x();   info_jaw.triangle[i].first.y = result_first.y();   info_jaw.triangle[i].first.z = result_first.z();
		info_jaw.triangle[i].second.x = result_second.x();  info_jaw.triangle[i].second.y = result_second.y();  info_jaw.triangle[i].second.z = result_second.z();
		info_jaw.triangle[i].third.x = result_third.x();   info_jaw.triangle[i].third.y = result_third.y();   info_jaw.triangle[i].third.z = result_third.z();
	}

}

void initial_registration(STLINFO & info_jaw1, STLINFO & info_jaw2, Matrix3f & vec_eigen1, Matrix3f & vec_eigen2){

	initial_centroid_alignment(info_jaw1, info_jaw2);

	Matrix3f mat_rotation1, mat_rotation2, mat_rotation3, mat_rotation4;
	calc_mat_rotation(vec_eigen1, vec_eigen2, mat_rotation1, mat_rotation2, mat_rotation3, mat_rotation4);
	
	//STLINFO result_rotated_jaw1_1(info_jaw1), result_rotated_jaw1_2(info_jaw1), result_rotated_jaw1_3(info_jaw1), result_rotated_jaw1_4(info_jaw1);
	//applying_rotation(info_jaw1, mat_rotation1, result_rotated_jaw1_1);
	//applying_rotation(info_jaw1, mat_rotation2, result_rotated_jaw1_2);
	//applying_rotation(info_jaw1, mat_rotation3, result_rotated_jaw1_3);
	//applying_rotation(info_jaw1, mat_rotation4, result_rotated_jaw1_4);
	//stl_add_and_save("result_rotated_jaw_1.stl", result_rotated_jaw1_1, info_jaw2);
	//stl_add_and_save("result_rotated_jaw_2.stl", result_rotated_jaw1_2, info_jaw2);
	//stl_add_and_save("result_rotated_jaw_3.stl", result_rotated_jaw1_3, info_jaw2);
	//stl_add_and_save("result_rotated_jaw_4.stl", result_rotated_jaw1_4, info_jaw2);
	// rotation4 works well
	// above lines were used for test which rotation works well

	applying_rot(info_jaw1, mat_rotation4);

}
