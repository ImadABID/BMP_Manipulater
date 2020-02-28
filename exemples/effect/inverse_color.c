#include "D:\Imad_Donnes\Etude\Programmation\Projets\BMP_Manipulater\src\paint.h"

int main(){

    image img=open("img.bmp");
    pixel px;

    for(int i=0; i<img.l; i++){
        for(int j=0; j<img.h; j++){
           px=get_pixel(img,i,j);
           
           px.couleur.o1=255-px.couleur.o1;
           px.couleur.o2=255-px.couleur.o2;
           px.couleur.o3=255-px.couleur.o3;

           put_pixel(px);
        }
    }

    save_image(img);

    return 0;
}