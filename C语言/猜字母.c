#include <stdio.h>
#include <string.h>

int main (void)
{
	char s[1000][1000],t[1000];
	int i,j,n,x;
	scanf("%d",&x);
	while(x--){
		scanf("%d",&n);
		getchar();
		for(i=0;i<n;i++)
			gets(s[i]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(strcmp(s[i],s[j])==-1){
					strcpy(t,s[i]);
					strcpy(s[i],s[j]);
					strcpy(s[j],t);
				}
		puts(s[0]);
	}
	return 0;
} 
