#include <stdio.h>
#define Max 10000
int main(void)
{
	int m,i,n,t,a[Max];
	scanf("%d",&n);
	while(n){
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		m=0;
		for(i=1;i<n;i++)
			if(a[m]>a[i])
				m=i;
		if(m){
			t=a[m];
			a[m]=a[0];
			a[0]=t;
		}		
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		scanf("%d",&n);		
	}
	return 0;
}
