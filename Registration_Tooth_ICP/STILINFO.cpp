#include "STLINFO.h"

STLINFO::STLINFO() {
	header.resize(80);
}

STLINFO::STLINFO(STLINFO & ref)
{
	header.assign(ref.header.begin(), ref.header.end());
	num_of_triangle = ref.num_of_triangle;
	vec_norm.assign(ref.vec_norm.begin(), ref.vec_norm.end());
	triangle.assign(ref.triangle.begin(), ref.triangle.end());
	attribute_byte_count.assign(ref.attribute_byte_count.begin(), ref.attribute_byte_count.end());
	average_xyz = ref.average_xyz;

	X.assign(ref.X.begin(), ref.X.end());
	Y.assign(ref.Y.begin(), ref.Y.end());
	Z.assign(ref.Z.begin(), ref.Z.end());
}

void STLINFO::ready_for_spliting_foreach_triangle()
{
	//secure capacity
	vec_norm.resize(num_of_triangle);
	triangle.resize(num_of_triangle);
	X.resize(num_of_triangle * 3);
	Y.resize(num_of_triangle * 3);
	Z.resize(num_of_triangle * 3);
}

void STLINFO::copy_xyz_to_vec_closest()
{
	for (unsigned int i = 0; i < num_of_triangle; i++) {
		vec_closest.push_back({ triangle[i].first, 0 });
		vec_closest.push_back({ triangle[i].second, 0 });
		vec_closest.push_back({ triangle[i].third, 0 });
	}
}
