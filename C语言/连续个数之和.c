#include <stdio.h>
#define M 20
int main (void)
{
	int m,a[M],i,j,k,n,s,tag=1;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		scanf("%d",a+i);
	for(i=0;i<m&&tag;i++){
		s=0;
		for(j=i;j<m&&tag;j++){
			s+=a[j];
			if(s==n)	tag=0;
		}
	} 
	if(tag)	printf("NO");
	else{
		printf("YES\n");
		for(k=i-1;k<j;k++)
			printf("%d ",a[k]);
	}
}
