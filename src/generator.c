#include "generator.h"

image increment_image(image img_source){
    pixel px;
    int i; int j;
    for(i=0;i<img_source.h;i++){
        for(j=0;j<img_source.l;j++){
            px=get_pixel(img_source,i,j);
            if (!(px.couleur.o1==255 && px.couleur.o2==255 && px.couleur.o3==255)){
                px.couleur=increment_color(px.couleur);
                put_pixel(px);
                return img_source;
            }else{
                px.couleur.o1=0; px.couleur.o2=0; px.couleur.o3=0;
                put_pixel(px);
            }
        }
    }
}

color increment_color(color c){
    color next_color=c;
    if (c.o1!=255){
        next_color.o1+=1;
        return next_color;
    }
    if (c.o2!=255){
        next_color.o1=0;
        next_color.o2+=1;
        return next_color;
    }
    if (c.o3!=255){
        next_color.o1=0;
        next_color.o2=0;
        next_color.o3+=1;
        return next_color;
    }
    next_color.o1=0;next_color.o2=0;next_color.o3=0;
    return next_color;
}

pixel alien_pixel(image img){
    int i; int j; 
    for(i=0;i<img.l;i++){
        for (j=0;j<img.h;j++){
            pixel px=get_pixel(img,i,j);
            if(color_around_not_simillar())
                return px;
        }
    }
    pixel px;px.x=-1;
    return px;
}

bool color_around_not_simillar(pixel px){
    if(!(px.x-1<0)){
        pixel pxGM=get_pixel(px.img,px.x-1,px.y);
        bool C=color_simillar(pxGM.couleur,px.couleur);
        if(C)
            return false;
    }

    if(!(px.x+1>px.img.l)){
        pixel pxGM=get_pixel(px.img,px.x+1,px.y);
        bool C=color_simillar(pxGM.couleur,px.couleur);
        if(C)
            return false;
    }

    if(!(px.y-1<0)){
        pixel pxGM=get_pixel(px.img,px.x,px.y-1);
        bool C=color_simillar(pxGM.couleur,px.couleur);
        if(C)
            return false;
    }

    if(!(px.y+1>px.img.h)){
        pixel pxGM=get_pixel(px.img,px.x,px.y+1);
        bool C=color_simillar(pxGM.couleur,px.couleur);
        if(C)
            return false;
    }

    if(!(px.x-1<0 || px.y-1<0)){
        pixel pxGM=get_pixel(px.img,px.x-1,px.y-1);
        bool C=color_simillar(pxGM.couleur,px.couleur);
        if(C)
            return false;
    }

    if(!(px.x-1<0 || px.y+1>px.img.h)){
        pixel pxGM=get_pixel(px.img,px.x-1,px.y+1);
        bool C=color_simillar(pxGM.couleur,px.couleur);
        if(C)
            return false;
    }

    if(!(px.x+1>px.img.l || px.y-1<0)){
        pixel pxGM=get_pixel(px.img,px.x+1,px.y-1);
        bool C=color_simillar(pxGM.couleur,px.couleur);
        if(C)
            return false;
    }
    
    if(!(px.x+1>px.img.l || px.y+1>px.img.h)){
        pixel pxGM=get_pixel(px.img,px.x+1,px.y+1);
        bool C=color_simillar(pxGM.couleur,px.couleur);
        if(C)
            return false;
    }
    printf("\nx=%d,y=%d\n",px.x,px.y);
    return true;
}

bool color_simillar(color c1, color c2){
    int d=abs(c1.o1-c2.o1)+abs(c1.o2-c2.o2)+abs(c1.o3-c2.o3);
    return (d<COLOR_MAX_DIFF);
}

int abs(int n){
    if (n<0)
        return -n;
    return n;
}