#include "STLINFO.h"


STLINFO::STLINFO() {
	header.resize(80);
}


void STLINFO::ready_for_spliting_foreach_triangle()
{
	//capacity secure
	vec_norm.resize(num_of_triangle);
	xyz_jaw.resize(num_of_triangle * 3);
}