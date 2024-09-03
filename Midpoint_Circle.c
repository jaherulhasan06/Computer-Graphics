#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void main()
{
int gd=DETECT,gm;
int xC,r,yC,i,x,y;
float d;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
printf("Enter the radius: ");
scanf("%d",&r);
printf("Enter X and Y coordinates of centre \n");
scanf("%d%d",&xC,&yC);
d=1.25-r;
x=0;
y=r;
do{
if(d<0){
x=x+1;
y=y;
d=d+2*x;
}
else{
x=x+1;
y=y-1;
d=d+2*x-2*y;
}
putpixel(xC+x,yC+y,14);
putpixel(xC-x,yC-y,12);
putpixel(xC+x,yC-y,13);
putpixel(xC-x,yC+y,4);
putpixel(xC+y,yC+x,15);
putpixel(xC-y,yC-x,6);
putpixel(xC+y,yC-x,7);
putpixel(xC-y,yC+x,8);
}
while(x<y);
getch();
closegraph();
}
