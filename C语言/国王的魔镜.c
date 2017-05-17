#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[100];
	int n,l,i,t,flag;
	scanf("%d",&n);
	getchar();
	while(n--){
		scanf("%s",s);
		l=strlen(s);
		if(l%2)	printf("%d\n",l);
		else{
			flag=0;
			while(1){
				for(i=0;i<l/2;i++)
				if(s[i]-s[l-i-1]){
					flag=1;
					printf("%d\n",l);
					break;
				}
			if(flag)	break;
			l/=2;
			if(l%2){
				printf("%d\n",l);
				break;
			}
			}
			
			
			
		} 
	}
	return 0;
}
