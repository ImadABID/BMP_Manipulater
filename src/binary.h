#ifndef __BINARY_H__
#define __BINARY_H__

#define _256P3 16777216
#define _256P2 65536

#include <stdlib.h>

/*
 * We mean by hexadicimal in this library an array
 * of caracter every carcter represent an oct
 * if we stock it using fwrite() we are going
 * to have the hexadecimal. 
 */

unsigned int HtoD(unsigned char *p);
unsigned char *DtoH(unsigned int e);

#endif