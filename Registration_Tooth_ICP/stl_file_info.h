#pragma once
#include <iostream>

class STLINFO {
public:
	unsigned char *header;
	int num_of_triangle;  // header & num_of_triangle are just for completing format not for using
	int size_of_file;	  // size_of_file is just for saving

	float *vec_norm;
	float *x;
	float *y;
	float *z;
	float *attribute_byte_count;

	STLINFO();
	void ready_for_spliting_foreach_triangle();
	void split_foreach_triangle(FILE *fp);
};