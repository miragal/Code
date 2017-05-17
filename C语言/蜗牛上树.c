#include <stdio.h>
int main (void)
{
	int n,h,i,t,s;
	scanf("%d",&n);
	while(n--){
		t=0;s=0; 
		scanf("%d",&h);
		for(i=0;;i++){
			s+=10;
			t++;
			if(s>=h){
				printf("%d\n",t);
				break;
			}	
			s-=5;
		}
	}
	return 0;
}
