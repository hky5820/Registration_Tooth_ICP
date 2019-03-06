#include "calc_mat_rotation.h"

void calc_mat_rotation(Matrix3f &vec_eigen1, Matrix3f &vec_eigen2, Matrix3f &result_mat_rotation1, Matrix3f &result_mat_rotation2, Matrix3f &result_mat_rotation3, Matrix3f &result_mat_rotation4) {
	
	Matrix3f mat_rotation1, mat_rotation2;

	for (int i = 0; i < 3; i++) {
		Vector3f principal_axis1 = vec_eigen1.col(2-i);
		Vector3f principal_axis2 = vec_eigen2.col(2-i);
		// already normalized
		// largest eigenvalue -> principal axis

		if (i == 1) {
			principal_axis1 = mat_rotation1 * principal_axis1;
		}

		Vector3f axis_rotation = principal_axis1.cross(principal_axis2);
		axis_rotation.normalize();
		
		float rotation_angle = acos(min(1.0f, principal_axis1.dot(principal_axis2)));

		
		mat_rotation1 = AngleAxisf(rotation_angle, axis_rotation);				// Matrix3f mat_rotation1 = AngleAxisf(...); doesn`t work. forced usage
		mat_rotation2 = AngleAxisf(-(M_PI - rotation_angle), axis_rotation);	// axis angle rotation
		
		if (i == 0) {
			result_mat_rotation1 = mat_rotation1;
			result_mat_rotation2 = mat_rotation1;
			result_mat_rotation3 = mat_rotation2;
			result_mat_rotation4 = mat_rotation2;
		}
		else if (i == 1) {
			result_mat_rotation1 = mat_rotation1 * result_mat_rotation1;
			result_mat_rotation2 = mat_rotation2 * result_mat_rotation2;
			result_mat_rotation3 = mat_rotation1 * result_mat_rotation3;
			result_mat_rotation4 = mat_rotation2 * result_mat_rotation4;
		}
	}

}