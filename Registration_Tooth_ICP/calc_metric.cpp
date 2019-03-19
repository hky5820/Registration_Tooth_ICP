#include "calc_metric.h"

#define SQ(a) ((a)*(a))

void apply_mat_to_point(XYZ &xyz, Matrix4f &mat) {
	Vector4f vec = { xyz.x, xyz.y, xyz.z, 1 };
	vec = mat * vec;
	xyz.x = vec.x();
	xyz.y = vec.y();
	xyz.z = vec.z();
}

void apply_mat_to_source(vector<pair<XYZ, XYZ>> &pair, Matrix4f &mat) {

	size_t size = pair.size();

	for (int i = 0; i < size; i++) {
		apply_mat_to_point(pair[i].first, mat);
	}

}

float calc_distance(pair<XYZ, XYZ> &pair) {
	return SQ(pair.first.x - pair.second.x) + SQ(pair.first.y - pair.second.y) + SQ(pair.first.z - pair.second.z);
}

float calc_metric(vector<pair<XYZ, XYZ>>& pair, Matrix4f & mat){

	size_t size = pair.size();
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += calc_distance(pair[i]);
	}

	return sum;
}
