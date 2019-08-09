#include<stdio.h>
 #include<conio.h>
#include<dos.h>
 #include<graphics.h>
 #include<stdlib.h>
 void main()
 {
   int i,steps,x1,y1,x2,y2,gd=DETECT,gm;
   int dx,dy,p,x,y;
   

   initgraph(&gd,&gm,"C:\\TC\\BGI");
   
   printf("Enter first point: ");
   scanf("%d %d",&x1,&y1);
   
   printf("Enter second point: ");
   scanf("%d %d",&x2,&y2);

   dx=x2-x1;
   dy=y2-y1;

   line(0,240,640,240);
   line(320,0,320,480);

   if(abs(dx)>=abs(dy))
		steps=abs(dx);
   else
		steps=abs(dy);
	
	x=x1;
	y=y1;
   
   if(abs(dx)>=abs(dy))
   {
	
	p=(2*abs(dy))-abs(dx);
	
	for(i=0;i<steps;i++)
	{
		if(p<0)
		{
			x=x+(dx/abs(dx));
			y=y;
			p=p+(2*abs(dy));
		}
		else
		{
			x=x+(dx/abs(dx));
			y=y+(dy/abs(dy));
			p=p+(2*abs(dy))-(2*abs(dx));
		}
	       //	if(i%4==0)          //for dotted
		if(i%20<=14 || i%20==16 || i%20==17)  //for dot dash
		putpixel(x+320,240-y,RED);   //i%16 for multicolour
	     /*	putpixel(x+320+1,240-y,RED);  //thick lines
		putpixel(x+320-1,240-y,RED);
	     */	delay(10);


	}
   }
   else
   {
	p=(2*abs(dx))-abs(dy);
	for(i=0;i<steps;i++)
	{
		if(p<0)
		{
			x=x;
			y=y+(dy/abs(dy));
			p=p+(2*abs(dx));
		}
		else
		{
			x=x+(dx/abs(dx));
			y=y+(dy/abs(dy));
			p=p+(2*abs(dx))-(2*abs(dy));
		}
	       //	if(i%4==0)                   //dotted
		if(i%20<=14 || i%20==16 || i%20==17) //dot dash
		putpixel(320+x,240-y,RED);          //i%16 for multicolour
		delay(10);
	}
   }
   getch();
   closegraph();  }