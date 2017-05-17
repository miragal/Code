#include <stdio.h>
int main (void)
{
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int b[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	int y,m,d,i,t,n;
	scanf("%d",&n);
	while(n--){
		t=0;
		scanf("%d%d%d",&y,&m,&d);
		if(y%400==0||y%4==0&&y%100){
			for(i=0;i<m-1;i++)
				t+=b[i];
		}
		else {
			for(i=0;i<m-1;i++)
				t+=a[i];
		}
		printf("%d\n",t+d);
	}
	
	return 0;
}
