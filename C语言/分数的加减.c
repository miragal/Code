#include <stdio.h>
#include <string.h>

int Min(int a,int b)
{
	int i;
	for(i=a;i<=a*b;i++)
		if(i%a==0&&i%b==0)	break;  
	return i;
} 
int Max(int a,int b)
{
	int i;
	for(i=a;i>=1;i--)
		if(a%i==0&&b%i==0)	break; 
	return i;
}

int main (void)
{
	char s[10],op;
	int a,b,c,d,x,y,t;
	while(scanf("%s",s)!=EOF){
		a=s[0]-'0';b=s[2]-'0';
		c=s[4]-'0';d=s[6]-'0';op=s[3];
		y=Min(b,d); 
		a=y/b*a;	c=y/d*c;
		if(op=='+')	x=a+c;
		else x=a-c;
		if(x==0)
			printf("0\n");
		else{
			t=Max(x,y);
			x=x/t;
			y=y/t;
			if(x%y==0)	printf("%d\n",x/y);
			else printf("%c/%c\n",x+'0',y+'0'); 
		}
	}
	return 0;
}
