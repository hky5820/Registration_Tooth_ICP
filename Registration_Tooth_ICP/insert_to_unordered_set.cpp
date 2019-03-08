#include "insert_to_unordered_set.h"

void insert_to_unordered_set(STLINFO & info_jaw1, STLINFO &info_jaw2, unordered_set<XYZ, hasher, compare> &point_set1, unordered_set<XYZ, hasher, compare> &point_set2){

	for (unsigned int i = 0; i < info_jaw1.num_of_triangle; i++) {
		point_set1.insert(info_jaw1.triangle[i].first);
		point_set1.insert(info_jaw1.triangle[i].second);
		point_set1.insert(info_jaw1.triangle[i].third);
	}
	for (unsigned int i = 0; i < info_jaw2.num_of_triangle; i++) {
		point_set2.insert(info_jaw2.triangle[i].first);
		point_set2.insert(info_jaw2.triangle[i].second);
		point_set2.insert(info_jaw2.triangle[i].third);
	}

}
