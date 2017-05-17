#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[1000];
	int i,a[256]={0};
	gets(s);
	for(i=0;s[i]-'#';i++)
		a[s[i]]++;
	for(i=0;i<256;i++)
		if(a[i]>0)
			printf("%c:%d\n",i,a[i]);
}
