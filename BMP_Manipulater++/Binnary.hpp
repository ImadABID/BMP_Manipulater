#if !defined(__BINNARY__)
#define __BINNARY__

#include<memory>
#include <iostream>

#define _256P3 16777216
#define _256P2 65536

class Binnary{
	public:
		static unsigned int HtoD(unsigned char *p);
		static unsigned char *DtoH(unsigned int e);
};

#endif