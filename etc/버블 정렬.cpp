
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
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			baeminhe[b] = a[i][j];
			b++;
		}		
	} 
	 
	for(i=0;i<25;i++){
		for(j=0;j<25-i-1;j++){
			if(baeminhe[j]>baeminhe[j+1]){
				nu =  baeminhe[j];
				baeminhe[j] = baeminhe[j+1];
				baeminhe[j+1] = nu;
			}
		}
	}
	
	b=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			a[i][j] = baeminhe[b];
			b++;
		}		
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d	",a[i][j]);
		}
		printf("\n");
	}
}
