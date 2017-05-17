#include <stdio.h>
int main(void)
{
	int x,i,a[1000]={0},l;
	while(scanf("%d",&x)!=EOF){
		l=0;
		if(!x)	printf("%d",a[0]);
		else{
			while(x){
			a[l++]=x%2;
			x/=2;
		}
		for(i=l-1;i>-1;i--)
			printf("%d",a[i]);
		}
		
		printf("\n");
	}
	return 0;	
} 
