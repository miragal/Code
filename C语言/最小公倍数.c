#include  <stdio.h>

int Fun(int a,int b)
{
	int i,j;
	for(i=a;i<=a*b;i++){
		if(i%a==0&&i%b==0)
			break;
	}
	return i;
}

int main(void)
{
	int n,x;
	while(scanf("%d",&n)!=EOF){
		x=n;
		printf("%d\n",Fun(n,x));
	}
	return 0;
 } 
