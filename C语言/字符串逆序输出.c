#include <stdio.h>
#include <string.h>
#define M 1000
int main(void)
{
	int n,i;
	char s[M];
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(s);
		for(i=strlen(s);i>-1;i--)
			if(s[i]>='a'&&s[i]<='z')
				printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
