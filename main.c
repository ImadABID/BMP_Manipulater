#include "color.h"

int main(){
    image img=open("img.bmp");
    printf("Adress: %s\n",img.path);
    printf("size: %d\n",img.size);
    printf("Longeur: %d\n",img.l);
    printf("Hauteur: %d\n",img.h);

    return 0;
}

