#include "initial_registration.h"

void initial_registration(STLINFO & info_jaw1, STLINFO & info_jaw2, Matrix3f & vec_eigen1, Matrix3f & vec_eigen2){

	translation_to_origin(info_jaw1, info_jaw2);

	Matrix3f mat_rotation1, mat_rotation2, mat_rotation3, mat_rotation4;
	calc_mat_rotation(vec_eigen1, vec_eigen2, mat_rotation1, mat_rotation2, mat_rotation3, mat_rotation4);
	
	STLINFO result_rotated_jaw1_1(info_jaw1), result_rotated_jaw1_2(info_jaw1), result_rotated_jaw1_3(info_jaw1), result_rotated_jaw1_4(info_jaw1);
	applying_rotation(info_jaw1, mat_rotation1, result_rotated_jaw1_1);
	applying_rotation(info_jaw1, mat_rotation2, result_rotated_jaw1_2);
	applying_rotation(info_jaw1, mat_rotation3, result_rotated_jaw1_3);
	applying_rotation(info_jaw1, mat_rotation4, result_rotated_jaw1_4);
	   
	stl_add_and_save("result_rotated_jaw_1.stl", result_rotated_jaw1_1, info_jaw2);
	stl_add_and_save("result_rotated_jaw_2.stl", result_rotated_jaw1_2, info_jaw2);
	stl_add_and_save("result_rotated_jaw_3.stl", result_rotated_jaw1_3, info_jaw2);
	stl_add_and_save("result_rotated_jaw_4.stl", result_rotated_jaw1_4, info_jaw2);

}
