#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100
typedef int Type;

typedef struct node
{
	int front,rear;
	Type data[M];
}Queue;

Queue *InitQueue()
{
	Queue *p;
	p=(Queue *)malloc(sizeof(Queue)); 
	p->front=p->rear=0;
	return p;
}

int InQueue(Queue *p,Type x)
{
	int s;
	if((p->rear+1)%M==p->front)	s=0;
	else{
		p->data[p->rear]=x;
		p->rear=(p->rear+1)%M;
		s=1;
	}
	return s;
}

int OutQueue(Queue *p,Type *x)
{
	int s;
	if(p->front==p->rear)	s=0;
	else{
		*x=p->data[p->front];
		p->front=(p->front+1)%M;
		s=1;
	}
	return s;
}

#define Max 20	
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

void Degree(Graph *g,int od[],int id[]);

void TraverseDFS(Graph g);

void DFS(Graph g,int vi);

void TraverseBFS(Graph g);

void BFS(Graph g,int vi);

int Locate(Graph *g,char c);

int main (void)
{
	Graph graph;
	int od[Max],id[Max],i; 
	Create(&graph);
	Degree(&graph,od,id);
	for(i=0;i<graph.vexnum;i++)
		printf("%c %d %d\n",graph.vex[i],od[i],id[i]);
	TraverseDFS(graph);
	printf("\n");
	fflush(stdin);
	TraverseBFS(graph);
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
	}
	
}

void Degree(Graph *g,int od[],int id[])
{
	int i,j;
	for(i=0;i<g->vexnum;i++){
		od[i]=0;
		for(j=0;j<g->vexnum;j++)
			if(g->arcs[i][j])
				od[i]++;
	}
	for(i=0;i<g->vexnum;i++){
		id[i]=0;
		for(j=0;j<g->vexnum;j++)
			if(g->arcs[j][i])
				id[i]++;
	}
}

void TraverseDFS(Graph g)
{
	int v;
	for(v=0;v<g.vexnum;v++)
		visit[v]=0;
	for(v=0;v<g.vexnum;v++)
		if(!visit[v])
			DFS(g,v);
}

void DFS(Graph g,int vi)
{
	int vj;
	printf("%c",g.vex[vi]);
	visit[vi]=1;
	for(vj=0;vj<g.vexnum;vj++)
		if(visit[vj]==0&&g.arcs[vi][vj]==1)
			DFS(g,vj);
}

void TraverseBFS(Graph g)
{
	int v;
	for(v=0;v<g.vexnum;v++)
		visit[v]=0;
	for(v=0;v<g.vexnum;v++)
		if(!visit[v])
			BFS(g,v);
}

void BFS(Graph g,int vi)
{
	Queue *p;
	int v,i;
	p=InitQueue(); 
	printf("%c",g.vex[i]);
	visit[vi]=1;
	InQueue(p,vi);
	while(p->front-p->rear){
		OutQueue(p,&v);
		for(i=0;i<g.vexnum;i++)
			if(!visit[i]&&g.arcs[v][i]==1){
				printf("%c",g.vex[i]);
				visit[i]=1;
				InQueue(p,i);
			}
	}
}


int Locate(Graph *g,char c)
{
	int i;
	for(i=0;i<g->vexnum&&g->vex[i]-c;i++);
	return i;
}
