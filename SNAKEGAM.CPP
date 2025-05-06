

#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

void snake();
void set();
void food();
void resetGame();
int ch;
int n=3;
int timer=120;
int x[100][4]={
{100,100,110,110},
{90,100,100,110},
{80,100,90,110}
};
int r1,r2;
int c=0;
char scoretext[20]={c};


void main()
{
int a=DETECT;
int b;
clrscr();
initgraph(&a,&b,"");
r1=50+random(450);
r2=50+random(350);

settextstyle(1,0,9);
outtextxy(45,120,"Snake Game");
settextstyle(2,0,7);
outtextxy(80,240,"Hit any Button to Start playing the Game!");
settextstyle(7,0,2);
outtextxy(40,280,"Controls:");
settextstyle(7,0,1);
outtextxy(40,300,"Use the Arrow Keys to move the snake:");

outtextxy(40,320,"Right Arrow (>) to Move Right");

outtextxy(40,340,"Left Arrow (<) to Move Left");

outtextxy(40,360,"Up Arrow (^) to Move Up");

outtextxy(40,380,"Down Arrow to Move Down");

//char down[2]={24,'\0'}; //Null terminator
//outtextxy(50,50,down);

do
{
ch=getch();
snake();
}
while(ch!=97);
getch();
}

void snake()
{
while(kbhit()==0)
{
int i;

sprintf(scoretext,"%d\n",c);
food();
for(i=0; i<n; i++)
{
    if(i == 0)
    {
	setcolor(RED);               // Head border color
	setfillstyle(SOLID_FILL, RED);  // Head fill color
    }
    else
    {
	setcolor(GREEN);             // Body border color
	setfillstyle(SOLID_FILL, GREEN); // Body fill color
    }

    rectangle(x[i][0], x[i][1], x[i][2], x[i][3]);

    // Fill inside of rectangle (middle point inside rectangle)
    floodfill((x[i][0] + x[i][2]) / 2, (x[i][1] + x[i][3]) / 2, getcolor());
}

if (ch==77)
{
set();
x[0][0]+=10;
x[0][2]+=10;
}
if (ch==75)
{
set();
x[0][0]-=10;
x[0][2]-=10;
}
if (ch==72)
{
set();
x[0][1]-=10;
x[0][3]-=10;
}
if (ch==80)
{
set();
x[0][1]+=10;
x[0][3]+=10;
}
setcolor(WHITE);
rectangle(1,1,630,470); //boundary
//boundary touch
if (x[0][0] <= 1 || x[0][2] >= 630 || x[0][1] <= 1 || x[0][3] >= 470)
{
    settextstyle(1,0,4);
    outtextxy(90,200,"Game Over : Boundary touched");
	resetGame(); // restart the game
		continue;
}
//self touch
for (int t = 1; t < n; t++)
{
    if (x[0][0] == x[t][0] && x[0][1] == x[t][1])
    {
	settextstyle(1, 0, 4);
	outtextxy(100, 200, "Self Poisoned - Game Over");
	resetGame();  //restart the game
	continue;

    }
}


if(x[0][0]==r1 && x[0][1]==r2)  //food eating
{
n++;
c+=10;
timer-=3;
r1=50+random(450);
r2=50+random(350);
}
delay(timer);
cleardevice();
settextstyle(2,0,6);
setcolor(YELLOW);
rectangle(500,15,628,50);
outtextxy(505,20,"score:");
outtextxy(570,20,scoretext);
}
}

void set()
{
int i;
for(i=n-1;i>0;i--)
{
x[i][0]=x[i-1][0];
x[i][1]=x[i-1][1];
x[i][2]=x[i-1][2];
x[i][3]=x[i-1][3];
}
}
void food()
{
r1=r1-r1%10;
r2=r2-r2%10;
settextstyle(0,0,2);
setcolor(LIGHTRED);
char heart[2]={3,'\0'}; //Null terminator
outtextxy(r1,r2,heart);
//rectangle(r1,r2,r1+10,r2+10);

}
void resetGame()
{
    n = 3;
    c = 0;
    timer = 120;
    x[0][0] = 100; x[0][1] = 100; x[0][2] = 110; x[0][3] = 110;
    x[1][0] = 90;  x[1][1] = 100; x[1][2] = 100; x[1][3] = 110;
    x[2][0] = 80;  x[2][1] = 100; x[2][2] = 90;  x[2][3] = 110;

    r1 = 50 + random(450);
    r2 = 50 + random(350);

    // show message and wait
    settextstyle(2, 0, 6);
    outtextxy(95, 250, "Game Over! Press any key to restart...");
    outtextxy(95, 270, "Your Score is:");
    outtextxy(240, 270,scoretext);
    getch();
    cleardevice();
}
