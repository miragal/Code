#include <stdio.h>
int Reverse(int n)
{
	int i,s=0;
	while(n){
		s=s*10+n%10;
		n/=10;
	}
	return s;
}

int main (void)
{
	int a,b,n;
	while(1){
		scanf("%d%d",&a,&b);
		if(!a&&!b)	break;
		printf("%d\n",Reverse(a)+Reverse(b));
	}
	return 0;
}
