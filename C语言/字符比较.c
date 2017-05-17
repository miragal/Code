#include <stdio.h>
int main(void)
{
//	int n;
//	char a,b;
//	scanf("%d",&n);
//	while(n--){
//		getchar();
//		scanf("%c %c",&a,&b);
//		if(a==b)	printf("%c=%c\n",a,b);
//		else if(a<b)	printf("%c>%c\n",a,b);
//			else printf("%c<%c\n",a,b);
//	}
	int i,j; 
	int a[][4] ={{1,2,3},{3,5},{5}};
	for(i=0;i<3;i++){
		for(j=0;j<4;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}	
	printf("%d ",sizeof(a));
	return 0;
}
