#include <stdio.h>
#include <string.h>
#define M 2000
#define N 1000

int main (void)
{
	char a[N],b[N],s[M];
	int k,k1,k2,i1,i2,cp,start;
	printf("请输入两个数：\n");
	gets(a);gets(b);
	start=M-2;
	s[N-1]=0;cp=0;
	i1=strlen(a)-1;i2=strlen(b)-1;
	while(i1>-1&&i2>-1){
		k1=a[i1--]-48;
		k2=b[i2--]-48;
		k=k1+k2+cp;
		s[start--]=k%10+48;
		cp=k/10;
	}
	while(i1>-1||i2>-1){
		k1=(i1>-1)?(a[i1--]-48):0;
		k2=(i2>-1)?(b[i2--]-48):0;
		k=k1+k2+cp;
		s[start--]=k%10+48;
		cp=k/10;
	}
	s[start--]=cp+48;
	if(s[start+1]=='0')		start++;
	puts(s+start+1);
	return 0;
}
 
