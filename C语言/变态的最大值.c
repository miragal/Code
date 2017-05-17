#include <stdio.h>
#define M 10000

int Max(int a[],int n);

int Min(int a[],int n);

int main (void)
{
	int n,a[M],b[M],i,cnt,c[3],d[3],t,s,m;
	while(scanf("%d",&n)){
		cnt=0;t=0;m=0;
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<n;i++){
			if(t==0){
				c[m++]=a[i];
				if(m==3){
					b[cnt++]=Max(c,3);
					m=0;
					t=1;
				}
			}
			else{
				d[m++]=a[i];
				if(m==3){
					b[cnt++]=Min(d,3);
					m=0;
					t=0;	
				}
			}
		}
		printf("%d\n",Max(b,cnt));
	}
	return 0;
}


int Max(int a[],int n)
{
	int m=-1000000,i;
	for(i=0;i<n;i++)
		if(m<a[i])
			m=a[i];
	return m;
}

int Min(int a[],int n)
{
	
	int m=1000000,i;
	for(i=0;i<n;i++)
		if(m>a[i])
			m=a[i];
	return m;
}

