#include <stdio.h>  
/*先考虑只有一行的情况，假设有b列 ，可以发现矩形长为b的有1个，b-1有2个，一直到长度为1，有b个 
    则这有（b+b-1+...+2+1） 
    列则一样的情况，(a+a-1+...+2+1)，那么有一行,长度为b的有b*a，两行有b*(a-1) 
    。。。 
    那么总共有（b+b-1+...+2+1）*(a+a-1+...+2+1) 
    =(b+1)*b/2 * (a+1)*a/2 
     
 
*/  
int main(void)  
{  
    long long a,b;  
    while(scanf("%lld%lld",&a,&b)!=EOF)  
    {  
        printf("%lld\n",a*(a+1)*b*(b+1)/4);  
    }  
    return 0;  
}  

