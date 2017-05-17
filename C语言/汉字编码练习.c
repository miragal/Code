#include <stdio.h>
#include <string.h>
int main (void)
{
	char s[]={"³Ô·¹"};
	char c;
	int i;
	printf("%d\n",strlen(s));
	for(i=0;i<strlen(s);i++){
		c=s[i];
		printf("%c",s[i]);	
	}
	// printf("%c",s[i]); 
	return 0;
}
