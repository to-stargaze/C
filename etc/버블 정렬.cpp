/*
1�� ����: for���� ���������� �̿��� 2���� �迭 ���� ����
	����
	1. �Է°� ����� 2���� �迭�� �Ͽ��� �Ѵ� 
	2. ���� ������ ���ʺ��� ������ ������ �Ʒ��� �Ѵ� 
	ex) 1 2 3
    4 5 6
    7 8 9
*/   

#include <stdio.h>

int main(){
	
	int a[5][5];
	int nu = 0;
	int baeminhe[25];
	int i,j,b=0;
	 
	printf("�迭�� �Է��Ͻÿ�\n");
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&a[i][j]);
		}
	}//�迭 �Է�
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			baeminhe[b] = a[i][j];
			b++;
		}		
	}//2���� �迭�� 1���� �迭�� �ٲ� 
	 
	for(i=0;i<25;i++){
		for(j=0;j<25-i-1;j++){
			if(baeminhe[j]>baeminhe[j+1]){
				nu =  baeminhe[j];
				baeminhe[j] = baeminhe[j+1];
				baeminhe[j+1] = nu;
			}
		}
	}//���� ����
	
	b=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			a[i][j] = baeminhe[b];
			b++;
		}		
	}//2���� �迭�� 1���� �迭�� �ٲ�  
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d	",a[i][j]);
		}
		printf("\n");
	}//�迭 �Է�	
}
