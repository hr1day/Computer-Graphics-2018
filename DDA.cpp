#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

int round(float num)
{
  return (int)(num < 0 ?num-0.5:num+0.5);
}


int main()
{
  int x1,x2,y1,y2,step,dx,dy,i,j,ch,th;
  float xi,yi,x,y;
  int gd=DETECT,gm=0;
  clrscr();

  //etectgraph(&gd,&gm);
  //initialize graph
  initgraph(&gd,&gm,"C:\\TC\\BGI");

  printf("Enter starting and end points\n");
  scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

  dx=x2-x1;
  dy=y2-y1;
  step=(abs(dx)>abs(dy)?abs(dx):abs(dy));
  printf("%d\n",step);

  xi=abs(dx);
  yi=abs(dy);
  xi/=step;
  yi/=step;
  
  printf("Enter type of line : \n");

  do
  {
    printf("1.Normal 2.Dash 3.Dot 4.Thick\n");
    scanf("%d",&ch);
    clrscr();
    x=x1,y=y1;
    
    switch(ch)
    {
      case 1:
      for(i=0;i<step;i++)
      {
      	putpixel(round(x),round(y),RED);
      	x=x+xi;
      	y=y+yi;
      }
      break;

      case 2:
      printf("Enter thickness\n");
      scanf("%d",&th);
      for(i=0;i<step;i++)
      {
    	if(i%10<5)
    	  for(j=0;j<th;j++)
    	    putpixel(round(x),round(y)+j,RED);
    	
      x=x+xi;
    	y=y+yi;
      }
      break;

      case 3:
      printf("Enter thickness\n");
      scanf("%d",&th);
      for(i=0;i<step;i++)
      {
	if(i%5==0)
	  for(j=0;j<th;j++)
	    putpixel(round(x),round(y)+j,RED);
	x=x+xi;
	y=y+yi;
      }
      break;

      case 4:
      printf("Enter thickness\n");
      scanf("%d",&th);
      for(i=0;i<step;i++)
      {
	for(j=0;j<th;j++)
	  putpixel(round(x),round(y)+j,RED);
	x=x+xi;
	y=y+yi;
      }
      break;

      default:
      if(ch!=5)
	printf("Invalid choice\n");
    }
  }while(ch!=5);

  getch();
  closegraph();

  return 0;
}
