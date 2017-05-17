#include <stdio.h>
int main (void)
{
	int a,b,i,j,n;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		for(i=1;i<=a;i++){
			for(j=i;j<=9;j++)
				printf("%d*%d=%d ",i,j,i*j);
			printf("\n");
		}
	}
	return 0;
}
