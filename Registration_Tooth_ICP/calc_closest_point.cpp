#include "calc_closest_point.h"

void calc_closest_point(STLINFO & info_jaw1, STLINFO & info_jaw2){

	pointVec points;

	for (unsigned int i = 0; i < info_jaw2.num_of_triangle * 3; i++) {
		points.push_back({ info_jaw2.X[i], info_jaw2.Y[i], info_jaw2.Z[i] });
	}

	KDTree tree_of_jaw2(points);
	cout << "complete making tree\n";

	for (unsigned int i = 0; i < info_jaw1.num_of_triangle * 3; i++) {

		pair<vector<double>,size_t> nearest_point = tree_of_jaw2.nearest_pointIndex({ info_jaw1.X[i], info_jaw1.Y[i], info_jaw1.Z[i] });
		info_jaw1.index_closest_point.push_back(nearest_point.second);

	}
	cout << "complete finding nearest point\n";
	for (int i = 0; i < 1000; i++) {
		cout << info_jaw1.index_closest_point[i] << " ";
	}
	cout << "\n";
}
