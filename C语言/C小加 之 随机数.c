#include <stdio.h>
int main (void)
#define M 1000
{
	int x,n,a[M],i,t,s;
	scanf("%d",&x);
	while(x--){
		for(i=0;i<M;i++)
			a[i]=0;
		s=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
		scanf("%d",&t);
		a[t]=1;
		}
		for(i=0;i<M;i++)
		if(a[i]==1)
		s++;
		printf("%d\n",s); 
		for(i=0;i<M;i++)
			if(a[i]==1)
			printf("%d ",i);
		printf("\n");
	}
	
	return 0;
}
