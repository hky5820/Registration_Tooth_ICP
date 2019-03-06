#include "calc_closest_point.h"

void calc_closest_point(STLINFO & info_jaw1, STLINFO & info_jaw2){

	info_jaw1.copy_xyz_to_vec_closest();

	pointVec points;

	for (unsigned int i = 0; i < info_jaw1.num_of_triangle * 3; i++) {
		points.push_back({ info_jaw1.vec_closest[i].first.x, info_jaw1.vec_closest[i].first.y , info_jaw1.vec_closest[i].first.z });
	}

	KDTree tree(points);

	for (unsigned int i = 0; i < info_jaw1.num_of_triangle * 3; i++) {
		//auto res = tree.nearest_point({ info_jaw1.vec_closest[i].first.x, info_jaw1.vec_closest[i].first.y , info_jaw1.vec_closest[i].first.z });
		pair<vector<double>,size_t> res = tree.nearest_pointIndex({ info_jaw1.vec_closest[i].first.x, info_jaw1.vec_closest[i].first.y , info_jaw1.vec_closest[i].first.z });
		cout << res.second << " ";
	}
}
