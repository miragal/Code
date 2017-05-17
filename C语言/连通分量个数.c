#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 20	//最大顶点个数
int visit[Max];
typedef char Vextype;
typedef struct
{
	int arcs[Max][Max];
	Vextype vex[Max];
	int vexnum;
	int arsnum;
}Graph;

void Create(Graph *g);

int TraverseDFS(Graph g);

void DFS(Graph g,int vi);

int Locate(Graph *g,char c);

int main (void)
{
	Graph graph;
	Create(&graph);
	printf("%d",TraverseDFS(graph));
	return 0;
}

void Create(Graph *g)
{
	int i,j,k,v1,v2;
	char a,b;
	scanf("%d%d",&(g->vexnum),&(g->arsnum));
	getchar(); 
	for(i=0;i<g->vexnum;i++)
		scanf("%c",&(g->vex[i]));
	for(i=0;i<g->vexnum;i++)
		for(j=0;j<g->vexnum;j++)
		g->arcs[i][j]=0;
	getchar();
	for(k=0;k<g->arsnum;k++){
		scanf("%c%c",&a,&b);
		getchar(); 
		v1=Locate(g,a);
		v2=Locate(g,b);
		(g->arcs)[v1][v2]=1;
		(g->arcs)[v2][v1]=1;
	}
	
}

int TraverseDFS(Graph g)
{
	int v,count=0;
	for(v=0;v<g.vexnum;v++)
		visit[v]=0;
	for(v=0;v<g.vexnum;v++)
		if(!visit[v]){
			DFS(g,v);
			count++;
		}
	return count;
}

void DFS(Graph g,int vi)
{
	int vj;
	visit[vi]=1;
	for(vj=0;vj<g.vexnum;vj++)
		if(visit[vj]==0&&g.arcs[vi][vj]==1)
			DFS(g,vj);
}

int Locate(Graph *g,char c)
{
	int i;
	for(i=0;i<g->vexnum&&g->vex[i]-c;i++);
	return i;
}
