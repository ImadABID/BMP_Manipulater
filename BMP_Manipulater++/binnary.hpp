#if !defined(__BINNARY__)
#define __BINNARY__

#include<memory>

#define _256P3 16777216
#define _256P2 65536

class Binnary{
public:
	static unsigned int HtoD(std::unique_ptr<unsigned char[]> p);
	static std::unique_ptr<unsigned char[]> DtoH(unsigned int e);
};

#endif