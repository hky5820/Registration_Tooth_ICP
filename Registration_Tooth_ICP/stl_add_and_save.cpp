#include "stl_add_and_save.h"

void stl_add_and_save(const char * name, STLINFO & info_jaw1, STLINFO & info_jaw2){

	FILE *fp = fopen(name, "wb");
	if (fp == NULL) exit(0);

	fwrite(info_jaw1.header.data(), sizeof(unsigned char), 80, fp);

	unsigned int sum_num_of_triangle = info_jaw1.num_of_triangle + info_jaw2.num_of_triangle;
	fwrite(&sum_num_of_triangle, sizeof(unsigned int), 1, fp);

	for(int i = 0; i <  )
}
