#include <stdio.h>
int main (void)
{
	int a,b,i,j,t;
	while(1){
		t=1;
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)	break; 
		for(i=1;i<=b&&t;i++){
			j=b/i;
			if(i+j==a)	t=0;
		}
		if(t)	printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
