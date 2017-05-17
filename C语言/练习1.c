#include <stdio.h>
#define N 100

int visit[N];

void DFS(int g[][N],int a,int v);

int main (void)
{
	int g[N][N],i,j,a,b,m,n;
	//初始化
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			g[N][N]=0;
	 printf("请输入顶点和边：");
	 scanf("%d%d",&a,&b);
	 //读入顶点和边
	 printf("请输入边："); 
	 for(i=1;i<=a;i++){
	 	scanf("%d%d",&m,&n);
	 	g[m][n]=1;
	 	g[n][m]=1;
	 } 
	 for(i=0;i<a;i++){
	 	for(j=0;j<a;j++)
	 		printf("%5d",g[i][j]);
	 	printf("\n");
	 }
//	DFS(g,a,1); 
	return 0;	
} 

void DFS(int g[][N],int a,int v)
{
	int i,j;
	for(i=1;i<=N;i++)
		visit[i]=0;
	printf("%d",v);
	visit[v]=1;
	for(i=1;i<=a;i++)
		if(g[v][i]==1&&visit[i]==0){
			visit[i]=1;
			DFS(g,a,i);
		}
			
}
