#include "initial_registration.h"
#include "applying_rotation.h"

void initial_registration(STLINFO & info_jaw1, STLINFO & info_jaw2, Matrix3f & vec_eigen1, Matrix3f & vec_eigen2, Matrix3f &result_init_registration){

	Matrix3f mat_rotation1, mat_rotation2, mat_rotation3, mat_rotation4;
	STLINFO result_rotated_jaw1(info_jaw1), result_rotated_jaw2(info_jaw1), result_rotated_jaw3(info_jaw1), result_rotated_jaw4(info_jaw1);
	calc_mat_rotation(vec_eigen1, vec_eigen2, mat_rotation1, mat_rotation2, mat_rotation3, mat_rotation4);
	applying_rotation(info_jaw1, mat_rotation1, result_rotated_jaw1);
	applying_rotation(info_jaw1, mat_rotation2, result_rotated_jaw2);
	applying_rotation(info_jaw1, mat_rotation3, result_rotated_jaw3);
	applying_rotation(info_jaw1, mat_rotation4, result_rotated_jaw4);


}
