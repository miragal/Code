#include <stdio.h>
#include <math.h>

#define P 3.1415926
int main (void)
{
	int n;
	double x,r;
	scanf("%d",&n);
	while(n--){
		scanf("%lf",&x);
		printf("%.2lf\n",P*pow(x*sqrt(3)/3,2));
	}
	return 0;
} 
