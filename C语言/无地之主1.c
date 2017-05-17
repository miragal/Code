#include <stdio.h>
#define M 1000 
typedef struct 
{
	int area;
	int num;
}G;

int main (void)
{
	G g[M];
	int n,m,i,j=0;
	while(scanf("%d%d",&m,&n)!=EOF){
		if(!m&&!n)	break;
		for(i=0;i<j;i++){
			if(g[i].area==m){
				g[i].num+=n;
				break;
			}
		}
		if(i==j){
			g[i].area=m;
			g[i].num=n;
			j++;
		}
	}
	for(i=0;i<j;i++)
		printf("%d %d\n",g[i].area,g[i].num);
	return 0;     
}
