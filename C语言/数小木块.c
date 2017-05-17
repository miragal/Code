#include <stdio.h>
int main(void)
{
	int x,n,i,s;
	scanf("%d",&n);
	while(n--){
		s=0;
		scanf("%d",&x);
		for(i=1;i<=x;i++)
			s+=i*(i+1)/2;
		printf("%d\n",s);
	}
	return 0;	
} 
