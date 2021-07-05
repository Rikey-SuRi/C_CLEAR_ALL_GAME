#include<stdio.h>
#include<conio.h>

int UnClear[20][40];
int x=20,y=10,stop=0;

int ClearBar(int move)
{
	static int delay=0;
	if((x==1 || x==37) || (y==0 || y==19))
	{
		stop=1;
		Box(x,y);
		return 1;
	}
	if(delay==10)
	{
		if(move==1) //up
			Box(x,--y);
		else if(move==2) //down
			Box(x,++y);
		else if(move==3) //right
			Box(++x,y);
		else if(move==4) //left
			Box(--x,y);
		delay=0;
	}
	else
		Box(x,y);
	if(move==1 || move==2 || move==3 || move==4)
		UnClear[y][x+1]=1;
	UnClear[y][x]=1;
	delay++;

	return 0;
}

int Box(int x,int y)
{
	int index1,index2;
	textcolor(LIGHTRED);
	for(index1=0;index1<20;index1++)
	{
		for(index2=0;index2<40;index2++)
		{
			if((index1==0 || index1==19) || (index2<2 || index2>37))
				if(stop==1)
					cprintf("%c",219);
				else
					printf("%c",219);
			else if((index1==y && index2==x) || (index1==y && index2==x+1))
				printf("%c",219);
			else if(UnClear[index1][index2]==0)
				printf("%c",176);
			else
				printf(" ");
		}printf("\n");
	}
	printf("\n...Press 'x' to view Result and Exit...");

	return 0;
}

int Info()
{
	gotoxy(10,8);
	printf(":.....CLEAR ALL GAME.....:\n\n");
	printf("=============================================\n");
	printf("  Instructions:\n\n");
	printf("\tPress Rignt Arrow to Turn Right\n\t Press Left Arrow to Turn Left");
	printf("\n\t   Press Up Arrow to Turn Up\n\t Press Down Arrow to Turn Down");
	printf("\n_____________________________________________\n\n");
	printf("\t  Press Enter to Start Game\n");
	printf("\n\t\t    ---X---");

	return 0;
}

int main()
{
	char ch;
	int move=0,exit=0,Result=0;
	int index1,index2;
	clrscr();
	for(index1=0;index1<20;index1++)
		for(index2=0;index2<40;index2++)
			UnClear[index1][index2]=0;
	Info();
	getch();
	clrscr();
	while(1)
	{
		gotoxy(1,1);
		if(!kbhit())
			exit=ClearBar(move);
		else if(kbhit())
		{
			ch=getch();
			if(ch==0x48) //up
				move=1;
			else if(ch==0x50) //down
				move=2;
			else if(ch==0x4d) //right
				move=3;
			else if(ch==0x4b) //left
				move=4;
			else if((int)ch==120)
				break;
			exit=ClearBar(move);
		}
		else if(exit==1)
			break;
	}
	for(index1=0;index1<20;index1++)
		for(index2=0;index2<40;index2++)
		{
			if((index1>0 && index1<19) && (index2>1 && index2<38))
			{
				if(UnClear[index1][index2]==0)
					Result=1;
			}
		}
	gotoxy(10,11);
	if(Result==0)
		printf("***You Won the Game***");
	else
		printf("***You Lost the Game***");
	getch();

	return 0;
}