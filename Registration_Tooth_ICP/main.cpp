#include "STLINFO.h"
#include "load_stl_file.h"

int main() {

	STLINFO info_jaw1, info_jaw2;
	load_stl_file("jaw1.stl", info_jaw1);
	load_stl_file("jaw2.stl", info_jaw2);

	return 0;
}