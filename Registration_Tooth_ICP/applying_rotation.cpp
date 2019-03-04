#include "applying_rotation.h"

void applying_rotation(STLINFO &info_jaw, Matrix3f &mat, STLINFO &result_jaw) {

	for (int i = 0; i < info_jaw.num_of_triangle * 3; i++) {
		result_jaw.X[i] = mat[0] * info_jaw.X[i] + mat[1] * info_jaw.Y[i] + mat[2] * info_jaw.Z[i];
		result_jaw.Y[i] = mat[3] * info_jaw.X[i] + mat[4] * info_jaw.Y[i] + mat[5] * info_jaw.Z[i];
		result_jaw.Z[i] = mat[6] * info_jaw.X[i] + mat[7] * info_jaw.Y[i] + mat[8] * info_jaw.Z[i];
	}

}