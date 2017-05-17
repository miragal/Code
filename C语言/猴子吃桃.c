#include <stdio.h>
int main (void)
{
	int n,m,i,s;
	scanf("%d",&n);
	while(n--){
		s=1; 
		scanf("%d",&m);
		for(i=0;i<m;i++)
			s=2*(s+1);
		printf("%d\n",s);
	}
	return 0;
}
