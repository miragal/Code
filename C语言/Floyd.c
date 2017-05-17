#include <stdio.h>
#define M 100
#define N 65535

int main(void)
{
	int a,f[M][M],i,j,k,weight,m=0,s=0;
	scanf("%d",&a);
	for(i=0;i<a;i++)
		for(j=0;j<a;j++)
			if(i-j)	f[i][j]=N;
			else f[i][j]=0;
	for(k=0;k<a-1;k++){
		scanf("%d%d%d",&i,&j,&weight);
		f[i-1][j-1]=weight;
		f[j-1][i-1]=weight;
	}
	for(i=0;i<a;i++)
		for(j=0;j<a;j++)
			for(k=0;k<a;k++)	
				if(f[i][j]>f[i][k]+f[k][j])
					f[i][j]=f[i][k]+f[k][j];
	
	for(i=0;i<a;i++)
		for(j=0;j<a;j++)
			if(f[i][j]>m&&f[i][j]<N)
				m=f[i][j];
	for(i=1;i<=m;i++)
		s=s+i+10;
	printf("%d",s);
	return 0;
}
