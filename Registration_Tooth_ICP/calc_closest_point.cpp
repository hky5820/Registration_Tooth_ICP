#include "calc_closest_point.h"
#include "insert_to_unordered_set.h"

void calc_closest_point(STLINFO & info_jaw1, STLINFO & info_jaw2, vector<pair<XYZ, XYZ>> &pair_closest_point){

	unordered_set<XYZ, hasher, compare> point_set1, point_set2;

	insert_to_unordered_set(info_jaw1, info_jaw2, point_set1, point_set2);

	struct kdtree *tree_of_jaw2 = kd_create(3);
	for (auto itr = point_set2.begin(); itr != point_set2.end(); itr++) {
		auto &xyz = *itr;
		kd_insert3f(tree_of_jaw2, xyz.x, xyz.y, xyz.z, 0);
	}

	XYZ xyz_nearest_point;

	struct kdres *nearest_point = 0;
	float arr_nearest_point[3] = { 0 };
	for (auto itr = point_set1.begin(); itr != point_set1.end(); itr++) {

		auto &xyz = *itr;
		
		nearest_point = kd_nearest3f(tree_of_jaw2, xyz.x, xyz.y, xyz.z);
		kd_res_itemf(nearest_point, arr_nearest_point);
		kd_res_free(nearest_point);

		xyz_nearest_point.x = arr_nearest_point[0]; 
		xyz_nearest_point.y = arr_nearest_point[1]; 
		xyz_nearest_point.z = arr_nearest_point[2];

		pair_closest_point.push_back( make_pair(xyz, xyz_nearest_point) );
	}

	kd_free(tree_of_jaw2);

}