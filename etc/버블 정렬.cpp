/*
1번 문제: for문과 버블정렬을 이용한 2차원 배열 숫자 나열
	조건
	1. 입력과 출력은 2차원 배열로 하여야 한다 
	2. 정렬 순서는 왼쪽부터 오른쪽 위부터 아래로 한다 
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
	 
	printf("배열을 입력하시오\n");
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&a[i][j]);
		}
	}//배열 입력
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			baeminhe[b] = a[i][j];
			b++;
		}		
	}//2차원 배열을 1차원 배열로 바꿈 
	 
	for(i=0;i<25;i++){
		for(j=0;j<25-i-1;j++){
			if(baeminhe[j]>baeminhe[j+1]){
				nu =  baeminhe[j];
				baeminhe[j] = baeminhe[j+1];
				baeminhe[j+1] = nu;
			}
		}
	}//버블 정렬
	
	b=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			a[i][j] = baeminhe[b];
			b++;
		}		
	}//2차원 배열을 1차원 배열로 바꿈  
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d	",a[i][j]);
		}
		printf("\n");
	}//배열 입력	
}
