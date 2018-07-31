#include "color.h"
#include "binary.h"

int main(){
    
    unsigned char *p=malloc(4); p=DtoH(129);
    
    printf("%d\t",p[0]);
    printf("%d\t",p[1]);
    printf("%d\t",p[2]);
    printf("%d\t",p[3]);

    p[0]=129;
    p[1]=0;
    p[2]=0;
    p[3]=0;

    
    printf("\n%d",HtoD(p));
    unsigned int x= 126*16777216;
   // printf("\n%d",x);

    printf("\n%d",sizeof(unsigned int));
    return 0;
}

