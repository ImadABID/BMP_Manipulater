#include "D:\Imad_Donnes\Etude\Programmation\Projets\BMP_Manipulater\src\paint.h"

int main(){

    image img=open("img.bmp");
    pixel px;

    for(i=0;i<img.l;i++){
        for(j=0;j<img.h;j++){
           px=get_pixel(img,i,j);
           
           px.coulour.o1=255-px.coulour.o1;
           px.coulour.o2=255-px.coulour.o2;
           px.coulour.o3=255-px.coulour.o3;

           put_pixel(px);
        }
    }

    save_image(img);

    return 0;
}