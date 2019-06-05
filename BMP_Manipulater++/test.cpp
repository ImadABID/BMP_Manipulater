#include "Bmp.hpp"
#include <iostream>


int main(){
	Bmp img{"test.bmp",-1,-1};
	img.save();

	
	return 0;
}