
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
	printf("����� ������ �����ϼ��� \n1. ���� 2. ������\n");
	scanf("%d",&a);
	if(a>2||a<1){
		printf("�ٽü����Ͻÿ�\n"); 
	}
	playerstate();
	if(a==1){
		printf("����� �����Դϴ�. ��������\n");
	}
	else if(a==2){
		printf("����� �������Դϴ� ��������\n");
	}
	
	while(1)
	{
		printf("����� ü��:%d, ������ ü��:%d\n",pl.hp,mon.hp);
		printf("\n����� ���ݽõ�\n");
		plbattle();
		printf("\n������ ���ݽõ�\n");
		monbattle();
		if(mon.hp<=0){
			printf("����� ü��:%d, ������ ü��:0\n",pl.hp); 
			printf("����� �¸��Դϴ�\n");
			printf("���� ����"); 
			break;
		}
		else if(pl.hp<=0){
			printf("����� ü��:0, ������ ü��:%d\n",mon.hp); 
			printf("����� �й��Դϴ�\n");
			printf("���� ����"); 
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
	int k = Attackstatus();//���� ���� ���� ����
	
	if(a==1){
	printf("1. ȸ��, 2. �÷�ġ��,3. �Ӹ�ġ��\n");
	scanf("%d",&b);
	} 
	else if(a==2){
	printf("1. ȸ��, 2. �Ҳ� ��, 3. �� ������\n"); 
	scanf("%d",&b);
	} //���� ���� 

	
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
		printf("ȸ��\n");
	} //ȸ��
	
	if(k!=0){ 
		if(b==2){
			if(k==2){
				mon.hp = mon.hp - pl.power*2;
				printf("���ݼ���\n");
				}	
			else if(k==1){
				mon.hp = mon.hp - (pl.power*2 + 30);
				printf("ũ��Ƽ�ð��ݼ���\n");
				}
				
			}//2�� ����  
			 
		if(b==3){
			if(k==2){
				mon.hp = mon.hp - pl.power;
				printf("���ݼ���\n");
				}	
			else if(k==1){
				mon.hp = mon.hp - pl.power;
				printf("ũ��Ƽ�ð��ݼ���\n");
				printf("���ͱ���\n");
				stern = 2;//2�ϰ� ���ϵ� �� ����� ������ �� �ʱ�ȭ  
				}                          
				//3�� ���� 
		}
		
		if(k==0)//10�ۼ�Ʈ ���� ����  
		{
			printf("���ݽ���\n");
		}
		if(b>3||b<1)
		{
			printf("��ų�� 1,2,3���� �ϳ��� ����ֽʽÿ�\n");
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
}//�Ϲ� Ȯ��

int Attackstatus1(){
	int c1;
	srand(time(NULL));
	c1=rand()%5+1;
	if(c1==1||c1==3) return 0;
	else if(c1==2) return 1;
	else return 2;
}//���� ü���� 300���� �϶��� Ȯ��  

void monbattle(){
	int k = Attackstatus();//���� ���� ���� ����
	int k1 = Attackstatus1();
	if(stern==0)
	{
		if(mon.hp>300){ 
			if(k==0){
				mon.hp = mon.hp + 70;
				printf("���Ͱ� ȸ���߽��ϴ�\n\n");
			}
			else if(k==1){
				printf("���� ���ݽ���\n\n");
			}
			else{
				pl.hp = pl.hp - mon.power;
				printf("���Ϳ��� ���ݹ޾ҽ��ϴ�\n\n");
			}
		}
		else if(mon.hp<301){
			if(k==0){
				mon.hp = mon.hp + 70;
				printf("���Ͱ� ȸ���߽��ϴ�\n\n"); 
			}
			else if(k==1){
				printf("���� ���ݽ���\n\n");
			}
			else{
				pl.hp = pl.hp - mon.power;
				printf("���Ϳ��� ���ݹ޾ҽ��ϴ�\n\n");
			}
		}
	}
	else if(stern!=0)
	{
		stern--;
	}
}
