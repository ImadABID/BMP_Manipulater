#include "binaire.h"

unsigned int HtoD(unsigned char *p){
    return p[0]*16777216+p[1]*65536+p[2]*256+p[3];
}