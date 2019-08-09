#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>

#define SIZE 20000

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

void floodFill(int x, int y, int oldColor, int newColor)
{
	push(x, y);
	while (!isEmpty())
	{
		y = pop();
		x = pop();
		putpixel(x, y, newColor);
		if (getpixel(x + 1, y) == oldColor)
			push(x + 1, y);
		if (getpixel(x - 1, y) == oldColor)
			push(x - 1, y);
		if (getpixel(x, y + 1) == oldColor)
			push(x, y + 1);
		if (getpixel(x, y - 1) == oldColor)
			push(x, y - 1);
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	circle(320,240,50);
	floodFill(320, 240, 0, 3);

	getch();

	closegraph();
	return 0;
}