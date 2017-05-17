#include <stdio.h>
int main (void)
{
	int x,n,j,s=0;
	printf("please input x and n:");
	scanf("%d%d",&x,&n);
	while(s<n){
		for(j=2;j<x&&x%j;j++);
		if(x==j){
			printf("%5d",x);
			s++;
		}
		x++;
	}
	return 0;
}
