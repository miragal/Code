#include <stdio.h>
#define N 1000
int main (void)
{
	int a[N],i,j,k,cp,x,y;
	int s;	//岗哨
	printf("请输入底数和指数：");
	scanf("%d%d",&x,&y);
	a[N-1]=1;	s=N-2;
	for(i=1;i<=y;i++){
		j=N-1;
		cp=0;
		while(j>s){
			k=a[j]*x+cp;
			a[j]=k%10;
			cp=k/10;
			j--; 
		}
		while(cp){
			a[s--]=cp%10;
			cp/=10;
		}
	} 
	for(i=s+1;i<N;i++)
		printf("%d",a[i]);
	return 0;
}
