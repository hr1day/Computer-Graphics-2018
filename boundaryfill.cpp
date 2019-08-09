/****STACK IMPLEMENTATION*****/
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#define SIZE 15000

int myStack[SIZE];
int top = -1;

void push(int x, int y)
{
	if (top == SIZE - 2) //Since i have to add 2 points;
	{
		cout << "Stack overflow : ";
		return;
	}

	myStack[++top] = x;
	myStack[++top] = y;
}

int pop()
{
	if (top == -1)
	{
		cout << "Error : Stack Empty :(";
		return -1;
	}

	int popped = myStack[top];
	top--;
	return popped;
}

int isEmpty()
{
	if (top == -1)
		return 1;
	return 0;
}

void boundaryFill(int x, int y, int fillColor, int boundaryColor)
{
	push(x, y);
	while (!isEmpty())
	{
		y = pop();
		x = pop();
		putpixel(x, y, fillColor);
		delay(1);
		if (getpixel(x + 1, y) != boundaryColor && getpixel(x + 1, y) != fillColor)
		{
			push(x + 1, y);
		}
		if (getpixel(x - 1, y) != boundaryColor && getpixel(x - 1, y) != fillColor)

		{
			push(x - 1, y);
		}
		if (getpixel(x, y + 1) != boundaryColor && getpixel(x, y + 1) != fillColor)
		{
			push(x, y + 1);
		}
		if (getpixel(x, y - 1) != boundaryColor && getpixel(x, y - 1) != fillColor)
		{
			push(x, y - 1);
		}
	}
}
	int main()
	{
		int gd = DETECT, gm;
		initgraph(&gd, &gm, "C:\\TC\\BGI");
		
		rectangle(100, 100, 200, 200);
		boundaryFill(150, 150, 3, 15);
		
		getch();
		closegraph();

		return 0;
	}	