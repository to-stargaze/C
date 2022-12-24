#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include <conio.h>
struct states{
	int Hp;
	int Mp;
	int Atk;
	int Dfs;
	int exp;
	int pos[2]={0,0};
	int mapNumber=0;
};
struct monstates{
	int Hp;
	int Mp;
	int Atk;
	int Dfs;
	int pos[2]={0,0};
};

struct states p1;

void move();

int main(void) 
{
	system("mode con: cols=40 lines=31");
	srand(time(NULL));
	int x,y;
	x=y=0;
	char c;
	int mx[20],my[20];
	for(int i=0;i<20;i++)
	{
		mx[i]=rand()%29+1;
		my[i]=rand()%39+1;
	}
	map(p1.mapNumber,p1.pos[0],p1.pos[1],mx,my);
	while(1)
	{
		int hx=p1.pos[0],hy=p1.pos[1];
		char c=getHistoryMap(0,hx,hy);
		if(kbhit()==1){
		move();
		movepos(p1.mapNumber,hx,hy,p1.pos[0],p1.pos[1],mx,my,c);
		}
	}
}


void move()
{	a:
	
	char c=getch();
		if(c=='w')
		p1.pos[0]--;
		else if(c=='d')
		p1.pos[1]++;
		else if(c=='s')
		p1.pos[0]++;
		else if(c=='a')
		p1.pos[1]--;
		else
		goto a;
		if(p1.pos[0]<=0)
		p1.pos[0]=0;  
		if(p1.pos[1]<=0)
		p1.pos[1]=0;
		if(p1.pos[0]>29)
		p1.pos[0]=28;  
		if(p1.pos[1]>39)
		p1.pos[1]=38;
}


