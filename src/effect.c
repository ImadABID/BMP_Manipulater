#include "effect.h"

image merge(image img1, image img2, char *output_path){
    int l=((img1.l>img2.l)?img2.l:img1.l);
    int h=((img1.h>img2.h)?img2.h:img1.h);
    image img_out=set_image(output_path,l,h);
    pixel px;
    int sizeofTab=3*l*h;
    int *Tab=malloc(4*sizeofTab);
    int iTab=0;
    int i,j;
    for(i=0;i<l;i++){
        for(j=0;j<h;j++){
            px=get_pixel(img1,i,j);
            Tab[iTab]=px.couleur.o1;
            Tab[iTab+1]=px.couleur.o2;
            Tab[iTab+2]=px.couleur.o3;

            px=get_pixel(img2,i,j);
            Tab[iTab]+=px.couleur.o1;
            Tab[iTab+1]+=px.couleur.o2;
            Tab[iTab+2]+=px.couleur.o3;
            iTab+=3;
        }
    }

    for(i=0;i<sizeofTab;i++){
        Tab[i]=(int)(Tab[i]/2);
    }

    px.img=img_out;
    iTab=0;
    for(i=0;i<l;i++){
        for(j=0;j<h;j++){
            px.x=i; px.y=j;
            px.couleur.o1=Tab[iTab];
            px.couleur.o2=Tab[iTab+1];
            px.couleur.o3=Tab[iTab+2];
            iTab+=3;
            put_pixel(px);
        }
    }
    return img_out;
}