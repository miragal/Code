#include <stdio.h>

#define Max 20	//最大顶点个数

int visit[Max];

typedef struct
{
	int arcs[Max][Max];
	int vexnum;
	int arsnum;
}Graph;

void Create(Graph *g);

int TraverseDFS(Graph g);

void DFS(Graph g,int vi);


int main (void)
{
	Graph graph;
	int i,s; 
	Create(&graph);
	s=TraverseDFS(graph);
	printf("%d",s);
	return 0;
}

void Create(Graph *g)
{
	int i,j,k,v1,v2;
	scanf("%d%d",&(g->vexnum),&(g->arsnum));
	for(i=0;i<g->vexnum;i++)
		for(j=0;j<g->vexnum;j++)
			g->arcs[i][j]=0;
	for(k=0;k<g->arsnum;k++){
		scanf("%d%d",&v1,&v2);
		(g->arcs)[v1-1][v2-1]=1;
		(g->arcs)[v2-1][v1-1]=1;
	}
}

int TraverseDFS(Graph g)
{
	int i,v,count=0;
	for(i=0;i<g.vexnum;i++){
		for(v=0;v<g.vexnum;v++)
			visit[v]=0;
		for(v=i;v<g.vexnum;v++){
			if(!visit[v]){
				DFS(g,v);
			}
			count++;
		}
	}
	return count;
}


void DFS(Graph g,int vi)
{
	int vj,count=0;
	visit[vi]=1;
	for(vj=0;vj<g.vexnum;vj++)
	//没被访问且有关系 
		if(visit[vj]==0&&g.arcs[vi][vj]){
				DFS(g,vj);
				count++;
				if(count=3)	return;
		}
		
}
