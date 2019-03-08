#pragma once
#include <unordered_set>
#include "STLINFO.h"

struct hasher {
	size_t operator()(const XYZ &point) const {
		float value = point.x * 31 * 31 + point.y * 31 + point.z;
		return std::hash<float>()(value);
	}
};

struct compare {
	bool operator()(const XYZ &point1, const XYZ &point2) const {
		if ((point1.x == point2.x) && (point1.y == point2.y) && (point1.z == point2.z)) return true;
		return false;
	}
};

void insert_to_unordered_set(STLINFO & info_jaw1, STLINFO & info_jaw2, unordered_set<XYZ, hasher, compare> &point_set1, unordered_set<XYZ, hasher, compare> &point_set2);