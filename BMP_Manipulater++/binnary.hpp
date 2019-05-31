#if !defined(__BINNARY__)
#define __BINNARY__

#define _256P3 16777216
#define _256P2 65536

#include <stdlib.h>

class Binnary{
public:
	unsigned int HtoD(std::unique_ptr<unsigned char[]> p);
	std::unique_ptr<unsigned char[]> DtoH(unsigned int e);
};

#endif