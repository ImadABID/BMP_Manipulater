#include"paint.h"

bool colorcmp(color c1, color c2){
    if(c1.o1!=c2.o1) return false;
    if(c1.o2!=c2.o2) return false;
    if(c1.o3!=c2.o3) return false;

    return true;
}