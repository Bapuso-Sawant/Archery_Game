//  PROJECT-NAME:: ARCHERY_GAME
//  PROGRAMMER  :: BAPUSO SAWANT
//  DATE	:: 3 MAY 2019
//  LANGUAGE	:: C LANGUAGE

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int c=4; 	//no of arrows
int cnt=0;	//percent during loading
int Your_score=0;

void text();
void load1();
void loading();
void choices();
void help();
void level1();
void level2();
void level3();
void level4();
void b1();
void b2();
void b3();
void b4();
void b5();
void b6();
void b7();
void sticks();
void msg();
void horzline();
void score();
int check1();
int check2();
int check3();
int check4();
int check5();
int check6();
int check7();

void main()
{
	int gd=0,gm,i,j;
	load1();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();
	loading();
	choices();
	getch();
	closegraph();
}

void load1()
{
	int i,j;
	clrscr();
	gotoxy(1,9);
	gotoxy(36,12);
	printf("LOADING...");
	textcolor(14);
	gotoxy(3,13);
	cprintf("%c",218);
	for(i=1;i<=75;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",191);
	gotoxy(3,14);
	for(i=2;i<=77;i++)
	{
		cprintf("%c",196);
	}
	gotoxy(3,14);
	cprintf("%c",192);
	gotoxy(79,14);
	cprintf("%c",217);
	for(i=3,j=10;i<=79;i++,j++)
	{
		textcolor(12);
		delay(i);
		gotoxy(38,15);
		if(i==79)
			printf("100%");
		else
		printf("%d%",j);
		gotoxy(i,13);
		cprintf("%c",220);
		gotoxy(i,14);
		cprintf("%c",223);
	}
	delay(200);
	clrscr();
}

void loading()
{
	int gd=0,gm,i,a=110,b=230;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	text();
	setcolor(12);
	arc(a,b,270,450,60);
	line(a-30,b,a,b-60);
	line(a-30,b,a,b+60);

	line(a-30,b,a+100,b);
	line(a+98,b-5,a+100,b);
	line(a+98,b+5,a+100,b);
	delay(1000);
	cleardevice();
	text();
	arc(a,b,270,450,60);
	line(a,170,a,290);
	line(a,b,a+100,b);
	line(a+98,b-5,a+100,b);
	line(a+98,b+5,a+100,b);

	for(i=a;i<=639;i=i+5)
	{
		cleardevice();
		text();
		arc(a,b,270,450,60);
		line(a,170,a,290);
		line(i,b,i+100,b);
		line(i+98,b-5,i+100,b);
		line(i+98,b+5,i+100,b);
		if(i>=615)
			cnt=100;
		else
			cnt++;
		delay(30);	//speed of arrow
	}
	delay(1000);
	cleardevice();
}
void text()
{
	char arr[50];
	settextstyle(4,0,8);
	setcolor(12);
	outtext("  Archery Game...");
	settextstyle(8,0,5);
	setcolor(6);
	sprintf(arr,"Please wait... %d%",cnt);
	outtextxy(210,370,arr);
	//border
	setcolor(10);
	rectangle(2,2,639,479);
}

void choices()
{
	int i;
	char ch;
	cleardevice();
	setbkcolor(10);
	settextstyle(7,0,5);
	setcolor(4);
	outtextxy(150,50,"Enter your choice:");
	settextstyle(8,0,2);
	setcolor(12);
	outtextxy(240,140,"1. Level 1");
	outtextxy(240,170,"2. Level 2");
	outtextxy(240,200,"3. Level 3");
	outtextxy(240,230,"4. Level 4");
	outtextxy(240,260,"5. Help");
	outtextxy(240,290,"6. Exit");
	c=4;	//After completing any level no of arrow again become 4

	setcolor(5);
	for(i=100;i<=539; i++)
	{
		outtextxy(i,350,"-");
	}
	fflush(stdin);
	scanf("%c",&ch);
	switch(ch)
	{
		case '1':
			 level1();
			 choices();
		case '2':
			 level2();
			 choices();
		case '3':
			 level3();
			 choices();
		case '4':
			 level4();
			 choices();
		case '5':
			 help();
			 choices();
		case '6':
			 exit(0);
		default:
			 cleardevice();
			 setcolor(8);
			 outtextxy(150,100,"Invalid input:");
			 outtextxy(150,150,"Please Enter valid input...");
			 delay(2000);
			 choices();
	}
}

void level1()
{
	int i,a=30,b=220,k;
	char ch;
	cleardevice();
	setcolor(15);
	setbkcolor(6);
	settextstyle(7,0,1);
	arc(a,b,270,450,30);
	line(a-10,b,a,b-30);
	line(a-10,b,a,b+30);

	line(a-10,b,a+50,b);
	line(a+48,b-5,a+50,b);
	line(a+48,b+5,a+50,b);
	rectangle(1,1,639,479);
	if(c==4)
		b2();
	if(c==3)
		b3();
	if(c==2)
		b1();
	if(c==1)
		b2();
	horzline();
	score();
	sticks();
	score();

	while(1)
	{
		ch=getch();
			if(ch==72)	//up
			{
				b--;
			}
			else if(ch==80)	//down
			{
				b++;
			}
			else if(ch==27)
			{
				break;
			}
			cleardevice();
			arc(a,b,270,450,30);
			line(a-10,b,a,b-30);
			line(a-10,b,a,b+30);
			line(a-10,b,a+50,b);
			line(a+48,b-5,a+50,b);
			line(a+48,b+5,a+50,b);
			rectangle(1,1,639,479);
			if(c==4)
				b2();
			if(c==3)
				b3();
			if(c==2)
				b1();
			if(c==1)
				b2();

			sticks();
			score();
			horzline();

			if(c==0)
			goto label;

			if(ch==32)
			{
				cleardevice();
				sound(110);
				delay(50);
				nosound();
				line(a,b,a,b-30);
				line(a,b,a,b+30);
				line(a,b,a+60,b);
				line(a+58,b-5,a+60,b);
				line(a+58,b+5,a+60,b);
				arc(a,b,270,450,30);
				rectangle(1,1,639,479);
				if(c==4)
				{
					 b2();
					 k=check2(b);
				}
				if(c==3)
				{
					 b3();
					 k=check3(b);
				}
				if(c==2)
				{
					b1();
					k=check1(b);
				}
				if(c==1)
				{
					b2();
					k=check2(b);
				}

				for(i=a;i<=k;i++)
				{
					cleardevice();
					line(a,b,a,b-30);
					line(a,b,a,b+30);
					line(i,b,i+60,b);
					line(i+58,b-5,i+60,b);
					line(i+58,b+5,i+60,b);
					arc(a,b,270,450,30);
					rectangle(1,1,639,479);
					if(i==k && k!=639 )
					{
						sound(500);
						delay(100);
						nosound();
					}
					if(i==k && k==639)
					{
						sound(80);
						delay(220);
						nosound();
					}
					if(c==4)
						b2();
					if(c==3)
						b3();
					if(c==2)
						b1();
					if(c==1)
						b2();

					sticks();
					outtextxy(320,20,"Score:");     // to just print syntax of score
					outtextxy(330,40,"Points: ");
					horzline();
					delay(2);	 //speed of arrow
				}
				score();  	//call it here bcoz after reaching arrow at particular position
				c--;
			}
	}
label:
	msg();
}

void level2()
{
	int i,a=30,b=220,k;
	char ch;
	cleardevice();
	setcolor(4);
	setbkcolor(7);
	settextstyle(7,0,1);
	arc(a,b,270,450,30);
	line(a-10,b,a,b-30);
	line(a-10,b,a,b+30);

	line(a-10,b,a+50,b);
	line(a+48,b-5,a+50,b);
	line(a+48,b+5,a+50,b);
	rectangle(1,1,639,479);
	if(c==4)
		b4();
	if(c==3)
		b1();
	if(c==2)
		b2();
	if(c==1)
		b4();
	horzline();
	score();
	sticks();
	score();

	while(1)
	{
		ch=getch();
			if(ch==72)	//up
			{
				b--;
			}
			else if(ch==80)	//down
			{
				b++;
			}
			else if(ch==27)
			{
				break;
			}
			cleardevice();
			arc(a,b,270,450,30);
			line(a-10,b,a,b-30);
			line(a-10,b,a,b+30);
			line(a-10,b,a+50,b);
			line(a+48,b-5,a+50,b);
			line(a+48,b+5,a+50,b);
			rectangle(1,1,639,479);
			if(c==4)
				b4();
			if(c==3)
				b1();
			if(c==2)
				b2();
			if(c==1)
				b4();

			sticks();
			score();
			horzline();

			if(c==0)
			goto label;

			if(ch==32)
			{
				cleardevice();
				sound(110);
				delay(50);
				nosound();
				line(a,b,a,b-30);
				line(a,b,a,b+30);
				line(a,b,a+60,b);
				line(a+58,b-5,a+60,b);
				line(a+58,b+5,a+60,b);
				arc(a,b,270,450,30);
				rectangle(1,1,639,479);
				sticks();
				horzline();
				score();
				if(c==4)
				{
					 b4();
					 k=check4(b);
				}
				if(c==3)
				{
					 b1();
					 k=check1(b);
				}
				if(c==2)
				{
					b2();
					k=check2(b);
				}
				if(c==1)
				{
					b4();
					k=check4(b);
				}

				for(i=a;i<=k;i++)
				{
					cleardevice();
					line(a,b,a,b-30);
					line(a,b,a,b+30);
					line(i,b,i+60,b);
					line(i+58,b-5,i+60,b);
					line(i+58,b+5,i+60,b);
					arc(a,b,270,450,30);
					rectangle(1,1,639,479);
					if(i==k && k!=639 )
					{
						sound(500);
						delay(100);
						nosound();
					}
					if(i==k && k==639)
					{
						sound(80);
						delay(220);
						nosound();
					}
					if(c==4)
						b4();
					if(c==3)
						b1();
					if(c==2)
						b2();
					if(c==1)
						b4();

					sticks();
					outtextxy(320,20,"Score:");     // to just print syntax of score
					outtextxy(330,40,"Points: ");
					horzline();
					delay(2);	 //speed of arrow
				}
				score();	 //call it here bcoz after reaching arrow at particular position
				c--;
			}
	}
label:
	msg();
}

void level3()
{
	int i,a=30,b=220,k;
	char ch;
	cleardevice();
	setcolor(5);
	setbkcolor(15);
	settextstyle(7,0,1);
	arc(a,b,270,450,30);
	line(a-10,b,a,b-30);
	line(a-10,b,a,b+30);

	line(a-10,b,a+50,b);
	line(a+48,b-5,a+50,b);
	line(a+48,b+5,a+50,b);
	rectangle(1,1,639,479);
	if(c==4)
		b4();
	if(c==3)
		b5();
	if(c==2)
		b2();
	if(c==1)
		b5();
	horzline();
	score();
	sticks();
	score();

	while(1)
	{
		ch=getch();
			if(ch==72)	//up
			{
				b--;
			}
			else if(ch==80)	//down
			{
				b++;
			}
			else if(ch==27)
			{
				break;
			}
			cleardevice();
			arc(a,b,270,450,30);
			line(a-10,b,a,b-30);
			line(a-10,b,a,b+30);
			line(a-10,b,a+50,b);
			line(a+48,b-5,a+50,b);
			line(a+48,b+5,a+50,b);
			rectangle(1,1,639,479);
			if(c==4)
				b4();
			if(c==3)
				b5();
			if(c==2)
				b2();
			if(c==1)
				b5();

			sticks();
			score();
			horzline();

			if(c==0)
			goto label;

			if(ch==32)
			{
				cleardevice();
				sound(110);
				delay(50);
				nosound();
				line(a,b,a,b-30);
				line(a,b,a,b+30);
				line(a,b,a+60,b);
				line(a+58,b-5,a+60,b);
				line(a+58,b+5,a+60,b);
				arc(a,b,270,450,30);
				rectangle(1,1,639,479);
				sticks();
				horzline();
				score();
				if(c==4)
				{
					 b4();
					 k=check4(b);
				}
				if(c==3)
				{
					 b5();
					 k=check5(b);
				}
				if(c==2)
				{
					b2();
					k=check2(b);
				}
				if(c==1)
				{
					b5();
					k=check5(b);
				}

				for(i=a;i<=k;i++)
				{
					cleardevice();
					line(a,b,a,b-30);
					line(a,b,a,b+30);
					line(i,b,i+60,b);
					line(i+58,b-5,i+60,b);
					line(i+58,b+5,i+60,b);
					arc(a,b,270,450,30);
					rectangle(1,1,639,479);
					if(i==k && k!=639 )
					{
						sound(500);
						delay(100);
						nosound();
					}
					if(i==k && k==639)
					{
						sound(80);
						delay(220);
						nosound();
					}
					if(c==4)
						b4();
					if(c==3)
						b5();
					if(c==2)
						b2();
					if(c==1)
						b5();

					sticks();
					outtextxy(320,20,"Score:");  // to just print syntax of score
					outtextxy(330,40,"Points: ");
					horzline();
					delay(2);	 //speed of arrow
				}
				score();	 //call it here bcoz after reaching arrow at particular position
				c--;
			}
	}
label:
	msg();
}

void level4()
{
	int i,a=30,b=220,k;
	char ch;
	cleardevice();
	setcolor(15);
	setbkcolor(5);
	settextstyle(7,0,1);
	arc(a,b,270,450,30);
	line(a-10,b,a,b-30);
	line(a-10,b,a,b+30);

	line(a-10,b,a+50,b);
	line(a+48,b-5,a+50,b);
	line(a+48,b+5,a+50,b);
	rectangle(1,1,639,479);
	if(c==4)
		b6();
	if(c==3)
		b7();
	if(c==2)
		b3();
	if(c==1)
		b7();
	horzline();
	score();
	sticks();
	score();

	while(1)
	{
		ch=getch();
			if(ch==72)	//up
			{
				b--;
			}
			else if(ch==80)	//down
			{
				b++;
			}
			else if(ch==27)
			{
				break;
			}
			cleardevice();
			arc(a,b,270,450,30);
			line(a-10,b,a,b-30);
			line(a-10,b,a,b+30);
			line(a-10,b,a+50,b);
			line(a+48,b-5,a+50,b);
			line(a+48,b+5,a+50,b);
			rectangle(1,1,639,479);
			if(c==4)
				b6();
			if(c==3)
				b7();
			if(c==2)
				b3();
			if(c==1)
				b7();

			sticks();
			score();
			horzline();

			if(c==0)
			goto label;

			if(ch==32)
			{
				cleardevice();
				sound(110);
				delay(50);
				nosound();
				line(a,b,a,b-30);
				line(a,b,a,b+30);
				line(a,b,a+60,b);
				line(a+58,b-5,a+60,b);
				line(a+58,b+5,a+60,b);
				arc(a,b,270,450,30);
				rectangle(1,1,639,479);
				sticks();
				horzline();
				score();
				if(c==4)
				{
					 b6();
					 k=check6(b);
				}
				if(c==3)
				{
					 b7();
					 k=check7(b);
				}
				if(c==2)
				{
					b3();
					k=check3(b);
				}
				if(c==1)
				{
					b7();
					k=check7(b);
				}

				for(i=a;i<=k;i++)
				{
					cleardevice();
					line(a,b,a,b-30);
					line(a,b,a,b+30);
					line(i,b,i+60,b);
					line(i+58,b-5,i+60,b);
					line(i+58,b+5,i+60,b);
					arc(a,b,270,450,30);
					rectangle(1,1,639,479);
					if(i==k && k!=639 )
					{
						sound(500);
						delay(100);
						nosound();
					}
					if(i==k && k==639)
					{
						sound(80);
						delay(220);
						nosound();
					}
					if(c==4)
						b6();
					if(c==3)
						b7();
					if(c==2)
						b3();
					if(c==1)
						b7();

					sticks();
					outtextxy(320,20,"Score:");     // to just print syntax of score
					outtextxy(330,40,"Points: ");
					horzline();
					delay(2);	 //speed of arrow
				}
				score();	 //call it here bcoz after reaching arrow at particular position
				c--;
			}
	}
label:
	msg();
}

// b1,b2,b3,b4,b5,b6,b7 are the blocks at where arrrow are shooted

void b1()
{
	//first    640,480
	rectangle(620,80,639,140);
	//second
	rectangle(605,90,620,130);
	//third
	rectangle(590,105,605,115);
}

void b2()
{
	//first    640,480
	rectangle(620,150,639,210);
	//second
	rectangle(605,160,620,200);
	//third
	rectangle(590,175,605,185);
}

void b3()
{
	//first    640,480
	rectangle(620,350,639,410);
	//second
	rectangle(605,360,620,400);
	//third
	rectangle(590,375,605,385);
}

void b4()
{
	//first    640,480
	rectangle(620,350,639,390);
	//second
	rectangle(605,360,620,380);
}

void b5()
{
	//first    640,480
	rectangle(630,250,639,290);
	//second
	rectangle(630,265,620,275);
}

void b6()
{
	rectangle(620,250,639,260);
}

void b7()
{
	rectangle(600,150,639,155);
}

int check1(int y)
{
	if(y>=80 && y<=90 || y>=130 && y<=140)
	{
		Your_score+=25;
		return 560;
	}
	else if(y>=90 && y<=100 || y>=120 && y<=130)
	{
		Your_score+=50;
		return 544;
	}
	else if(y>100 && y<120)
	{
		Your_score+=100;
		return 530;
	}
	else
	{
		Your_score=0;
		return 639;
	}
}

int check2(int y)
{
	if(y>=150 && y<=160 || y>=200 && y<=210)
	{
		Your_score+=25;
		return 560;
	}
	else if(y>=160 && y<=170 || y>=190 && y<=200)
	{
		Your_score+=50;
		return 544;
	}
	else if(y>170 && y<190)
	{
		Your_score+=100;
		return 530;
	}
	else
	{
		Your_score=0;
		return 639;
	}
}

int check3(int y)
{
	if(y>=350 && y<=360 || y>=400 && y<=410)
	{
		Your_score+=25;
		return 560;
	}
	else if(y>=360 && y<=370 || y>=390 && y<=400)
	{
		Your_score+=50;
		return 544;
	}
	else if(y>370 && y<390)
	{
		Your_score+=100;
		return 530;
	}
	else
	{
		Your_score=0;
		return 639;
	}
}

int check4(int y)
{
	if(y>=350 && y<=360 || y>=380 && y<=390)
	{
		Your_score+=50;
		return 560;
	}
	else if(y>360 && y<380)
	{
		Your_score+=100;
		return 544;
	}
	else
	{
		Your_score=0;
		return 639;
	}
}

int check5(int y)
{
	if(y>=250 && y<=265 || y>=275 && y<=290)
	{
		Your_score+=50;
		return 570;
	}
	else if(y>265 && y<275)
	{
		Your_score+=100;
		return 560;
	}
	else
	{
		Your_score=0;
		return 639;
	}
}

int check6(int y)
{
	if(y>=250 && y<=260)
	{
		Your_score+=100;
		return 560;
	}
	else
	{
		Your_score=0;
		return 639;
	}
}

int check7(int y)
{
	if(y>=150 && y<=155)
	{
		Your_score+=100;
		return 540;
	}
	else
	{
		Your_score=0;
		return 639;
	}
}

void sticks()
{
	int a=40,b=15,i;
	for(i=1;i<=c;i++)
	{
		line(a,b,90+a,b);
		line(a+88,b-5,a+90,b);
		line(a+88,b+5,a+90,b);
		b+=12;
	}
}

void horzline()
{
	line(1,65,639,65);
}

void msg()
{
	char arr[50];
	cleardevice();
	setcolor(4);
	setbkcolor(11);
	outtextxy(100,100,"Arrows are completed\n");
	sprintf(arr,"TOTAL SCORE : %d",Your_score);
	outtextxy(140,150,arr);
	delay(2000);
	Your_score=0;
}

void score()
{
	char arr[50];
	outtextxy(320,20,"Score:");
	sprintf(arr,"Points: %d",Your_score);
	outtextxy(330,40,arr);
}

void help()
{
	cleardevice();
	textcolor(15);
	setbkcolor(0);
	outtextxy(50,100,"Help:");
	outtextxy(80,150,"1. Enter ESC to exit during playing game");
	outtextxy(80,180,"2. Enter SPACE button to shoot");
	outtextxy(80,210,"3. Enter UP & DOWN key to move archery");
	outtextxy(80,250,"Enter any key to be continue...");
	getch();
}



