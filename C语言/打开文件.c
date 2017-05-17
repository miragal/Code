#include <stdio.h> 
#include <string.h> 
int main(void) 
{  
	char s[5]={'1','2','3','4',0};
	//puts(s);
	printf("%c\n",s[4]);
	printf("%d,%d",strlen(s),sizeof(s));
	
	/*
    FILE *fp=NULL;   
    char str[128];   
    if((fp=fopen("file1.txt","r"))==NULL) {  
        printf("cannot open file."); 	
		return 0;  
    }   
    while(!feof(fp)) {  
        if(fgets(str,128,fp)!=NULL)  
        printf("%s",str);  
    }  
    fclose(fp); 
	*/
	return 0; 
}   
