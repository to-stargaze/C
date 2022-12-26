
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int a,b,stern;

struct state{
	int hp;
	int power;
};

struct state mon;
struct state pl;

void monstate();
void playerstate();
void plbattle();
void monbattle(); 
int Attackstatus();
int Attackstatus2();

int main(){

	monstate();
	printf("당신의 직업을 선택하세요 \n1. 전사 2. 마법사\n");
	scanf("%d",&a);
	if(a>2||a<1){
		printf("다시선택하시오\n"); 
	}
	playerstate();
	if(a==1){
		printf("당신은 전사입니다. 전투시작\n");
	}
	else if(a==2){
		printf("당신은 마법사입니다 전투시작\n");
	}
	
	while(1)
	{
		printf("당신의 체력:%d, 몬스터의 체력:%d\n",pl.hp,mon.hp);
		printf("\n당신의 공격시도\n");
		plbattle();
		printf("\n몬스터의 공격시도\n");
		monbattle();
		if(mon.hp<=0){
			printf("당신의 체력:%d, 몬스터의 체력:0\n",pl.hp); 
			printf("당신의 승리입니다\n");
			printf("게임 종료"); 
			break;
		}
		else if(pl.hp<=0){
			printf("당신의 체력:0, 몬스터의 체력:%d\n",mon.hp); 
			printf("당신의 패배입니다\n");
			printf("게임 종료"); 
			break;
		} 
	}	                  	                  
}                 

void monstate(){
	mon.hp = 1000;
	mon.power = 60;
}

void playerstate(){
		if(a==1){
		pl.hp = 500;
		pl.power = 30;
		}
		else if(a==2){
		pl.hp = 300;
		pl.power = 40;	
		}		
}
void plbattle(){  
	int k = Attackstatus();//공격 상태 저장 변수
	
	if(a==1){
	printf("1. 회복, 2. 올려치기,3. 머리치기\n");
	scanf("%d",&b);
	} 
	else if(a==2){
	printf("1. 회복, 2. 불꽃 공, 3. 돌 날리기\n"); 
	scanf("%d",&b);
	} //직업 구별 

	
	if(b==1){
		if(a==1){
			pl.hp = pl.hp + 100;
			if(pl.hp>500)
			pl.hp = 500;
		}
		else if(a==2){
			pl.hp = pl.hp + 200;
			if(pl.hp>300)
			pl.hp = 300;
		}
		printf("회복\n");
	} //회복
	
	if(k!=0){ 
		if(b==2){
			if(k==2){
				mon.hp = mon.hp - pl.power*2;
				printf("공격성공\n");
				}	
			else if(k==1){
				mon.hp = mon.hp - (pl.power*2 + 30);
				printf("크리티컬공격성공\n");
				}
				
			}//2번 공격  
			 
		if(b==3){
			if(k==2){
				mon.hp = mon.hp - pl.power;
				printf("공격성공\n");
				}	
			else if(k==1){
				mon.hp = mon.hp - pl.power;
				printf("크리티컬공격성공\n");
				printf("몬스터기절\n");
				stern = 2;//2턴간 스턴될 때 사용할 변수의 값 초기화  
				}                          
				//3번 공격 
		}
		
		if(k==0)//10퍼센트 공격 실패  
		{
			printf("공격실패\n");
		}
		if(b>3||b<1)
		{
			printf("스킬은 1,2,3번중 하나로 골라주십시오\n");
		}
	}
}

int Attackstatus(){
	int c;
	srand(time(NULL));
	c=rand()%10+1;
	if(c==1) return 0;
	else if(c==2) return 1;
	else return 2;
}//일반 확률

int Attackstatus1(){
	int c1;
	srand(time(NULL));
	c1=rand()%5+1;
	if(c1==1||c1==3) return 0;
	else if(c1==2) return 1;
	else return 2;
}//몬스터 체력이 300이하 일때의 확률  

void monbattle(){
	int k = Attackstatus();//공격 상태 저장 변수
	int k1 = Attackstatus1();
	if(stern==0)
	{
		if(mon.hp>300){ 
			if(k==0){
				mon.hp = mon.hp + 70;
				printf("몬스터가 회복했습니다\n\n");
			}
			else if(k==1){
				printf("몬스터 공격실패\n\n");
			}
			else{
				pl.hp = pl.hp - mon.power;
				printf("몬스터에게 공격받았습니다\n\n");
			}
		}
		else if(mon.hp<301){
			if(k==0){
				mon.hp = mon.hp + 70;
				printf("몬스터가 회복했습니다\n\n"); 
			}
			else if(k==1){
				printf("몬스터 공격실패\n\n");
			}
			else{
				pl.hp = pl.hp - mon.power;
				printf("몬스터에게 공격받았습니다\n\n");
			}
		}
	}
	else if(stern!=0)
	{
		stern--;
	}
}
