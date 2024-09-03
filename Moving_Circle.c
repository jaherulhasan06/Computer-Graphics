#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>

void midcrl(int xc, int yc, int r)
{
int x,y;
float d;
d=1.25-r;
x=0;y=r;
do{
if(d<0)
{
x=x+1;
d=d+2*x+3;}
else{x=x+1;
y=y-1;
d=d+2*x-2*y+5;}
putpixel(xc+x,yc+y,5);
putpixel(xc-x,yc+y,5);
putpixel(xc+x,yc-y,5);
putpixel(xc-x,yc-y,5);
putpixel(xc+y,yc+x,5);
putpixel(xc-y,yc+x,5);
putpixel(xc+y,yc-x,5);
putpixel(xc-y,yc-x,5);
}
while(x<y);
}
void main() {
int xc,yc,r,i;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
for(i=1;i<=500;i++)
{
cleardevice();
midcrl(150+i,110,60);
line(170+i,170,250+i,170);
delay(5);
}
getch();
closegraph();
}
