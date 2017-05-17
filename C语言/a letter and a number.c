#include <stdio.h>
#include <string.h>
#define M 52 
typedef struct
{
	int a[M];
	char c[M];
}Type;

int main (void)
{
	Type t;
	int i,j,n;
	char c;
	for(i=0,c='a';c<='z';i++,c++){
		t.c[i]=c;
		t.a[i]=-(i+1);
	}
	for(j=1,c='A';c<='Z';i++,c++){
			t.c[i]=c;
			t.a[i]=j++;
	}		
	scanf("%d",&n);
	while(n--){
		getchar();
		scanf("%c%d",&c,&j);
		for(i=0;i<M;i++)
			if(t.c[i]==c)
				printf("%d\n",t.a[i]+j);
	}	
}
