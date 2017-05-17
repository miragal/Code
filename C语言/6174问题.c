#include <stdio.h>
#include <stdlib.h> 

int *Sort(int n);

int Max(int n);

int Min(int n);

int main (void)
{
	int n,x,cnt,y,t;
	scanf("%d",&n);
	while(n--){
		cnt=1;
		scanf("%d",&x);
		t=x;
		while(1){
			t=Max(x)-Min(x);
			cnt++;
			x=t;
			if(t==6174)	break;
		}
		printf("%d\n",cnt);
	}
	return 0;	
} 

int *Sort(int n)
{
	int i,j,t;
	int *a=(int *)malloc(sizeof(int)*4);
	a[0]=n/1000;
	a[1]=n/100%10;
	a[2]=n/10%10;
	a[3]=n%10;
	for(i=0;i<4;i++)
		for(j=i+1;j<4;j++)
			if(a[i]>a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
	return a;
}

int Max(int n)
{
	int *p=(int *)malloc(sizeof(int)*4);
	p=Sort(n);
	return p[3]*1000+p[2]*100+p[1]*10+p[0];
}


int Min(int n)
{
	int *p=(int *)malloc(sizeof(int)*4);
	p=Sort(n);
	return p[0]*1000+p[1]*100+p[2]*10+p[3];
}
