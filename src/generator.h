#include "bmp.h"

image increment_image(image img_source);
pixel alien_pixel(image img);//if there is no alien_pixel px.x=-1

color increment_color(color c);
#define COLOR_MAX_DIFF 80
bool color_simillar(color c1, color c2);
bool color_around_not_simillar(pixel px);

int abs(int n);