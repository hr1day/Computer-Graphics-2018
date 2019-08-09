#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void Circle(int r, int xc, int yc)
{
	int P, x = 0, y = r, i, Xmax, Ymax;
	
	P = 1 - r;
	while (x <= y)
	{
		
		putpixel(x  + xc,  y + yc, WHITE);
		putpixel(-x  + xc,  y + yc, WHITE);
		putpixel(x  + xc,  -y + yc, WHITE);
		putpixel(-x  + xc,  -y + yc, WHITE);
		putpixel(y  + xc,  x + yc, WHITE);
		putpixel(-y  + xc,  x + yc, WHITE);
		putpixel(y  + xc,  -x + yc, WHITE);
		putpixel(-y  + xc,  -x + yc, WHITE);
		


		x++;
		if (P < 0)
			P += 2 * x + 1;
		else
		{
			y--;
			P += 2 * x - 2 * y + 1;
		}
	}
}
void main()
{
	int r, xc, yc, Xmax, Ymax;
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "C:\\TC\\BGI");
	
	printf("Enter the radius of circle");
	scanf("%d", &r);
	
	printf("Enter Centre coordinates (xc,yc) : ");

	scanf("%d%d", &xc&yc);
	Circle(r, xc, yc);
	getch();
	closegraph();
}