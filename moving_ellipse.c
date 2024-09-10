#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

void drawEllipse(int xc,int yc,int rx,int ry) {
    int x,y;
    float d1;

    d1=(ry*ry)-(rx*rx*ry)+(0.25*rx*rx);
    x=0;
    y=ry;
    do {
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc-y,WHITE);

	if(d1<0) {
	    x++;
	    d1+=2*ry*ry*x+ry*ry;
	} else {
	    x++;
	    y--;
	    d1+=2*ry*ry*x-2*rx*rx*y+ry*ry;
	}
    } while(2*ry*ry*x<2*rx*rx*y);

    d1=(ry*ry*(x+0.5)*(x+0.5))+(rx*rx*(y-1)*(y-1))-(rx*rx*ry*ry);

    do {
	putpixel(xc+x, yc+y, RED);
	putpixel(xc-x, yc+y, RED);
	putpixel(xc+x, yc-y, RED);
	putpixel(xc-x, yc-y, RED);

	if (d1>0) {
	    y--;
	    d1-=2*rx*rx*y+rx*rx;
	} else {
	    x++;
	    y--;
	    d1-=2*rx*rx*y-2*ry*ry*x+rx*rx;
	}
    }
    while(y>=0);
}
int main() {
    int gd=DETECT,gm;
   /* printf("Enter the coordinates of x and y: \n");
    scanf("%f%f",&xc,&yc);
    printf("Enter the radius: \n");
    scanf("%f%f",&rx,&ry);   */
    int xc=100,yc=150;
    int rx=90,ry=110;
    int dx=5;
    initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
    while(!kbhit()){
    	cleardevice();
    	drawEllipse(xc,yc,rx,ry);
    	xc=dx+xc;
    	if(xc>getmaxx()-rx||xc<rx){
    		dx=-dx;
		}
		delay(5);
	}
	closegraph();
	return 0;
}
