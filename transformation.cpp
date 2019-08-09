#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#define N 20
#define pi 3.142


/*
GLOBAL DECLARATIONS
*/
int numOfVertices, array[N];
int myVerticesMatrix[N][N];
float translationMatrix[N][N];
float RotationMatrix[N][N];
float ReflectionMatrix[N][N];
float ShearingMatrix[N][N];
float ScalingMatrix[N][N];
int newMatrix[N][N];
int myArray[N];
int tx, ty;
int Sx, Sy;
int Shx,Shy;
float thetaInRadian, theta;




void drawPolygon(int drawArr[N],int color)
{
	setcolor(color);
	
	for (int i = 0; i <= numOfVertices + 1; i += 2)
		line(drawArr[i] + (getmaxx() / 2), (getmaxy() / 2) - drawArr[i + 1], drawArr[i + 2] +
			(getmaxx() / 2), (getmaxy() / 2) - drawArr[i + 3]);
	
	line(drawArr[i] + (getmaxx() / 2), (getmaxy() / 2) - drawArr[i + 1], (getmaxx() /
		2) + drawArr[0], (getmaxy() / 2) - drawArr[1]);
	
	setcolor(WHITE);
}


void drawAxes()
{
	line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
	line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
}



void Input()
{
	cout << "Enter the x y value of the vertices of polygon : " << endl;
	int i;
	for (i = 0; i < 2 * numOfVertices; i++)
	{
		cin >> array[i];
	}
	array[i++] = array[0];
	array[i] = array[1];
}

void formCoordinateMatrix()
{
	int k = 0;
	for (int i = 0; i < numOfVertices; i++)
		for (int j = 0; j < 3; j++)
		{
			if (j == 2)
				myVerticesMatrix[i][j] = 1;
			else
			{
				myVerticesMatrix[i][j] = array[k++];

			}
		}
}


void findTransformedMatrix(float transformationMatrix[N][N])
	{
		for (int i = 0; i < numOfVertices; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				newMatrix[i][j] = 0;
				for (int k = 0; k < 3; k++)
					newMatrix[i][j] += myVerticesMatrix[i][k] * transformationMatrix[k][j];
			}
		}
	}
	void createArrayFromMatrix()
	{
		int k = 0;
		for (int i = 0; i < numOfVertices; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				myArray[k++] = newMatrix[i][j];
			}
		}
		myArray[k++] = myArray[0];
		myArray[k] = myArray[1];
	}

// TRANSLATION//
	void formTranslationMatrix()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (i == j)
					translationMatrix[i][j] = 1;
				else
					translationMatrix[i][j] = 0;
			}
			translationMatrix[2][0] = tx;
			translationMatrix[2][1] = ty;
		}
		void Translate()
		{

			formTranslationMatrix();
			findTransformedMatrix(translationMatrix);
			createArrayFromMatrix();
			drawAxes();
			drawPolygon(myArray,GREEN);
		}
// END OF TRANSLATION //
//-----------------------------------------------------------------------

//ROTATION//
		void formRotationalMatrix()
		{
			RotationMatrix[0][0] = (float)cos(theta);
			RotationMatrix[0][1] = (float)sin(theta);
			RotationMatrix[0][2] = 0;
			RotationMatrix[1][0] = (float)(-sin(theta));
			RotationMatrix[1][1] = (float)cos(theta);
			RotationMatrix[1][2] = 0;
			RotationMatrix[2][0] = 0;
			RotationMatrix[2][1] = 0;
			RotationMatrix[2][2] = 1;
			getch();
		}

		void Rotate()
		{
			
			formRotationalMatrix();
			findTransformedMatrix(RotationMatrix);
			createArrayFromMatrix();
			drawAxes();
			drawPolygon(myArray,GREEN);
		}
//END OF ROTATION//
//--------------------------------------------------------
// Scaling //
		void formScalingMatrix()
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					ScalingMatrix[i][j] = 0;

				ScalingMatrix[0][0] = Sx;
				ScalingMatrix[1][1] = Sy;
				ScalingMatrix[2][2] = 1;
			}
			void SCALE()
			{
				formScalingMatrix();
				findTransformedMatrix(ScalingMatrix);
				createArrayFromMatrix();
				drawAxes();
				drawPolygon(myArray,GREEN);
			}
// End of Scaling //
//Reflection//
			void formReflectionMatrix(char choice)
			{
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
						ReflectionMatrix[i][j] = 0;
					if (choice == 'X')
					{
						ReflectionMatrix[0][0] = 1;
						ReflectionMatrix[1][1] = -1;
						ReflectionMatrix[2][2] = 1;
					}
					else if (choice == 'Y')
					{
						ReflectionMatrix[0][0] = -1;
						ReflectionMatrix[1][1] = 1;
						ReflectionMatrix[2][2] = 1;
					}
					else
					{
						ReflectionMatrix[0][0] = -1;
						ReflectionMatrix[1][1] = -1;
						ReflectionMatrix[2][2] = 1;
					}
			}
				void Reflection(char choice)

				{
					formReflectionMatrix(choice);
					findTransformedMatrix(ReflectionMatrix);
					createArrayFromMatrix();
					drawAxes();
					drawPolygon(myArray,GREEN);
				}
//End of Reflection//
//--------------------------------------------------------------
//Shearing//
				void formShearingMatrix(char choice)
				{
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++)
						{
							if (i == j)
								ShearingMatrix[i][j] = 1;
							else
								ShearingMatrix[i][j] = 0;
						}
						if (choice == 'Y')
							ShearingMatrix[0][1] = Shy;
						else if (choice == 'X')
							ShearingMatrix[1][0] = Shx;
						else
						{
							ShearingMatrix[0][1] = Shx;
							ShearingMatrix[1][0] = Shy;
						}
					}
					void Shearing(char choice)
					{

						formShearingMatrix(choice);
						findTransformedMatrix(ShearingMatrix);
						createArrayFromMatrix();
						drawAxes();

						drawPolygon(myArray,GREEN);
					}
//End of Shearing//
					int main()
					{
						int gd = DETECT, gm, k = 0;
						
						char choice;
//-----------------DECLARATIONS END-------------------------------//
						initgraph(&gd, &gm, "C:\\TC\\BGI");
						
						cout << "Enter the number of vertices of polygon : ";
						cin >> numOfVertices;
						
						Input();
						cleardevice();

						drawAxes();
						drawPolygon(array,WHITE);
						
						formCoordinateMatrix();
						int myChoice,exit = 0;
						
						while (1)
						{
							cout << "-------Menu Driven------\n";
							cout << "-----------------------------\n";
							cout << "1. Translation " << endl;
							cout << "2. Rotation " << endl;
							cout << "3. Scaling " << endl;
							cout << "4. Shearing " << endl;
							cout << "5. Reflection " << endl;
							cout << "6. Exit " << endl;
							cout << "Enter a choice : ";
							cin >> myChoice;
							switch (myChoice)
							{
								case 1:
								{
									cout << "Enter the value of tx and ty : ";
									cin >> tx >> ty;
									cout << "Translated in x => " << tx << "\nTranslated in y => " << ty <<
									endl;

									Translate();
									drawPolygon(array,WHITE);
									getch();
									cleardevice();
									break;
								}
								case 2:
								{
									cout << "ROTATION : " << endl;
									cout << "Enter the angle of rotation : " << endl;
									cin >> theta;
									theta = theta * ((float)pi / (float)180);
									cleardevice();
									cout << "ROTATED BY => " << theta << endl;
									Rotate();
									drawPolygon(array,WHITE);
									getch();
									cleardevice();
									break;
								}
								case 3:
								{
									cout << "Enter the value of Sx and Sy : ";
									cin >> Sx >> Sy;
									cout << "Scaled in x => " << Sx << "\nScaled in y => " << Sy << endl;
									SCALE();
									drawPolygon(array,WHITE);
									getch();
									cleardevice();
									break;
								}
								case 4:
								{

									cout << "Shearing about X OR Y axes OR BOTH ? : ";
									cin >> choice;
									if (choice == 'X')
									{
										cout << "Enter Shearing Factor Along X-axis : ";
										cin >> Shx;
										cout << "Shearing about X axis => " << endl;
									}
									else if (choice == 'Y')
									{
										cout << "Enter Shearing Factor Along Y-axis : ";
										cin >> Shy;
										cout << "Shearing about Y axis => " << endl;
									}

									else
									{
										cout << "Enter Shearing Factor Along X and Y axes : ";
										cin >> Shx >> Shy;
										cout << "Shearing about X and Y axes => " << endl;
									}
									Shearing(choice);
									drawPolygon(array,WHITE);
									getch();
									cleardevice();
									break;
								}
								case 5:
								{
									cout << "Reflection about X OR Y axes OR BOTH ? : ";
									cin >> choice;

									if (choice == 'X')
										cout << "Reflection about X axis => " << endl;
									else if (choice == 'Y')
										cout << "Reflection about Y axis => " << endl;
									else
										cout << "Reflection about X and Y axes => " << endl;
									
									Reflection(choice);
									drawPolygon(array,WHITE);
									getch();
									break;
								}
								case 6:
								{
									exit = 1;
									break;
								}
							}
							if (exit == 1)
								break;
						}
						getch();
						closegraph();
						return 0;
					}