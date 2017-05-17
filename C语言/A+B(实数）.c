#include<stdio.h>
int main(void)
{
    int n;
    double a,b,c;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        if(a+b-c<0.0001&&a+b-c>-0.0001)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
