#include <stdio.h>
#include <stdlib.h>
#define Max 20	//最大顶点个数
#define N 128 
int visit[Max];
typedef struct
{
	int arcs[Max][Max];
	int vexnum;
	int vex[Max];
	int arsnum;
	int t[Max];
}Graph; 

typedef struct{
	int adj;
	int lowcost;
}closedge[Max],close;

void Create(Graph *g);

close *Prim(Graph *g,int start);
 
int main (void)
{
	Graph graph;
	int i,s=0; 
	close *dge;
	Create(&graph);
	dge=Prim(&graph,0);
	for(i=0;i<graph.vexnum;i++)
		s+=dge[i].lowcost;
	printf("%d",s); 
	return 0;
}

void Create(Graph *g)
{
	int i,j,k,v1,v2,weight;
	scanf("%d%d",&(g->vexnum),&(g->arsnum));
	for(i=0;i<g->vexnum;i++)
		g->vex[i]=i+1;
	for(i=0;i<g->vexnum;i++)
		for(j=0;j<g->vexnum;j++)
		g->arcs[i][j]=N;
	for(k=0;k<g->arsnum;k++){
		scanf("%d%d%d",&v1,&v2,&weight);
		(g->arcs)[v1][v2]=weight;
		(g->arcs)[v2][v1]=weight;
	}
	for(i=0;i<g->vexnum;i++)
		scanf("%d",g->t+i);
}


close *Prim(Graph *g,int start)
{
	int i,e,k,m,min;
	closedge s;
	s[start].lowcost=0;//标志顶点u已加入到生成树集合
	//对除了出发点以外的所有顶点初始化对应的closedge数组 
	for(i=0;i<g->vexnum;i++){
		if(i-start){
			s[i].adj=start;
			s[i].lowcost=g->arcs[start][i];
		}
	}
	for(e=0;e<g->vexnum-1;e++){  //控制选中的n-1条符合条件的边 
		//选择最小权值的边
		min=N;
		for(k=0;k<g->vexnum;k++){
			if(s[k].lowcost&&s[k].lowcost<min){
				m=k;
				min=s[k].lowcost;
			}
		} 
		s[m].lowcost=0;//标志顶点v0加入到生成树集合 
		//当v0加入后，更新closedge数组信息
		for(i=0;i<g->vexnum;i++){
			if(i-m&&g->arcs[m][i]<s[i].lowcost){
				//一旦有更小的权值出现，则更新
				s[i].lowcost=g->arcs[m][i];
				s[i].adj=m; 
			}
		} 
	}
	return s;
}
