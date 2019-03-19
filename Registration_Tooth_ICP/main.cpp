#include "PCA_ICP_Registration.h"

int main() {

	PCA_ICP_Registration(
		"./Data_STL/jaw1.stl",
		"./Data_STL/jaw2.stl",
		"./Data_STL/result_PCA_ICP_Registration.stl");

	return 0;
}