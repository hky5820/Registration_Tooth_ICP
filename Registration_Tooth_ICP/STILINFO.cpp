#include "STLINFO.h"


STLINFO::STLINFO() {
	header.resize(80);
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