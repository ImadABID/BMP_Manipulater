#if ! defined(__BINNARY__)
#define(__BINNARY__)

#define _256P3 16777216
#define _256P2 65536

#include <stdlib.h>

class Binnary{
public:
	unsigned int HtoD(unsigned char *p);
	unsigned char *DtoH(unsigned int e);
}

#endif