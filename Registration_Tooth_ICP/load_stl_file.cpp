#include "load_stl_file.h"

void load_stl_file(const char * name, STLINFO & jaw)
{
	int size_of_file;
	
	FILE *fp = fopen(name, "rb");
	fseek(fp, 0, SEEK_END);
	size_of_file = ftell(fp);
	rewind(fp);

	fread(jaw.header, sizeof(unsigned char), 80, fp);
	fread(&jaw.num_of_triangle, sizeof(unsigned char), 1, fp);

	jaw.
}
