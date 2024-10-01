#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void flood_fill4(int x,int y,int f,int o)
{
int c;
c=getpixel(x,y);
if(c==o);
{
setcolor(f);
putpixel(x,y,f);
delay(3);
flood_fill4(x+1,y,f,o);
flood_fill4(x,y+1,f,o);
flood_fill4(x+1,y+1,f,o);
flood_fill4(x-1,y-1,f,o);
flood_fill4(x-1,y,f,o);
flood_fill4(x,y-1,f,o);
flood_fill4(x-1,y+1,f,o);
flood_fill4(x+1,y-1,f,o);
}
}
void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
rectangle(50,50,100,100);
flood_fill4(51,51,4,0);
getch();
}
