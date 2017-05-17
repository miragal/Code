#include <stdio.h>  
int main(void)  
{  
    int n;  
    int x,y;  
    char ch;  
    scanf("%d",&n);  
    while(n--)  
    {  
        scanf("%x%c%x",&x,&ch,&y);  
        if(ch == '+')  
        {  
            printf("%o\n",x+y);  
        }  
        else  
        {  
            printf("%o\n",x-y);  
        }  
    }  
    return 0;
}  
