#include <stdio.h>
#include <string.h>
#define M 1000
int main (void)
{
	char s[M];
	int n,i;
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(s);
		for(i=0;i<strlen(s);i++)
			if(s[i]=='@')	break;
		printf("%d\n",s[i+2]-'0');
	}
	return 0;	
} 
