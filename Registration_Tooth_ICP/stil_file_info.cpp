#include "stl_file_info.h"


STLINFO::STLINFO() {
	header = new unsigned char[80];
	memset(header, 0, sizeof(unsigned char) * 80);
}

void STLINFO::ready_for_spliting_foreach_triangle()
{
	vec_norm = new float[num_of_triangle * 3];
	x = new float[num_of_triangle * 3];
	y = new float[num_of_triangle * 3];
	y = new float[num_of_triangle * 3];
	memset(vec_norm, 0, sizeof(float) *num_of_triangle * 3);
	memset(x, 0, sizeof(float)*num_of_triangle * 3);
	memset(y, 0, sizeof(float)*num_of_triangle * 3);
	memset(z, 0, sizeof(float)*num_of_triangle * 3);
}

void STLINFO::split_foreach_triangle(FILE *fp)
{
	
}
