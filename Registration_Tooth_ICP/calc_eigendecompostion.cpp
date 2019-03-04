#include "calc_eigendecompostion.h"

void calc_eigendecomposition(Matrix3f &mat_convariance1, Matrix3f &mat_convariance2, Matrix3f &vec_eigen1, Matrix3f &vec_eigen2, Vector3f &value_eigen1, Vector3f &value_eigen2) {

	SelfAdjointEigenSolver<Matrix3f> es1, es2;
	es1.compute(mat_convariance1);
	es2.compute(mat_convariance2);

	vec_eigen1 = es1.eigenvectors();
	vec_eigen2 = es2.eigenvectors();

	value_eigen1 = es1.eigenvalues();
	value_eigen1 = es2.eigenvalues();
}