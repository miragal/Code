#include <stdio.h>
int main (void) 
{
	int i,a[4]={1,2,3,4};
	int *b[4];	//ָ������ 
	int (*c)[4];	//����ָ��
	for(i=0;i<4;i++)
		b[i]=a+i;
	c=&a;
	printf("%d,%d",*b[1],(*c)[0]);
	return 0;	
} 
