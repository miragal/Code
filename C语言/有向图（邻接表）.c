#include <stdio.h>
#include <stdlib.h>
#define Max 20
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

int visit[Max];
//边 
typedef struct ArcNode
{
	int adj;
	struct ArcNode *nextarc;
}ArcNode;

//顶点
typedef struct VertaxNode
{
	char data;
	struct ArcNode *firstarc;	
}VertaxNode;

//有向网
typedef struct 
{
	VertaxNode vertax[Max];		//顶点 
	int vernum;		//顶点数 
	int arcnum; 	//边数 
}ALGraph;
 
void CreateDG(ALGraph *g); 
 
int Locate(char c,ALGraph *g); 

void Degree(ALGraph g,int od[],int id[]); 

void TraverseDFS(ALGraph g);

void DFS(ALGraph g,int vi);

void TraverseBFS(ALGraph g);

void BFS(ALGraph g,int vi);

int main (void)
{
 	ALGraph graph;
 	int od[Max],id[Max],i;
	CreateDG(&graph);
	Degree(graph,od,id); 
	for(i=1;i<=graph.vernum;i++)
		printf("%c %d %d\n",graph.vertax[i].data,od[i],id[i]);
	TraverseDFS(graph);
	printf("\n");
	TraverseBFS(graph);
	return 0;
}

void CreateDG(ALGraph *g)
{
	char v1,v2;
	int i,j,k,weight;
	ArcNode *p,*s;
	scanf("%d%d",&(g->vernum),&(g->arcnum)); 
	getchar();
	for(i=1;i<=g->vernum;i++){
		scanf("%c",&(g->vertax[i].data));
		g->vertax[i].firstarc=NULL;
	} 
	getchar();
	for(k=1;k<=g->arcnum;k++){
		scanf("%c%c",&v1,&v2);
		getchar();	
		i=Locate(v1,g);
		j=Locate(v2,g);		
		s=(ArcNode *)malloc(sizeof(ArcNode));
		s->adj=j;
		s->nextarc=NULL;
		p=g->vertax[i].firstarc;
		if(!p)	g->vertax[i].firstarc=s;
			else if(p->adj>j){
				s->nextarc=p;
				g->vertax[i].firstarc=s;
			}
				else{
					while(p->nextarc&&p->nextarc->adj<j)
						p=p->nextarc;
					s->nextarc=p->nextarc;
					p->nextarc=s;	
				}
	} 
}

int Locate(char c,ALGraph *g)
{
	int i;
	for(i=1;i<=g->vernum&&g->vertax[i].data-c;i++);
	return i;	
}


void Degree(ALGraph g,int od[],int id[])
{
	int j,i;
	ArcNode *p;
	for(j=1;j<=g.vernum;j++)
		od[j]=id[j]=0;
	for(j=1;j<=g.vernum;j++){
		p=g.vertax[j].firstarc;
		while(p){
			od[j]++;
			i=p->adj;
			id[i]++;
			p=p->nextarc;	
		}
	}
}


void TraverseDFS(ALGraph g)
{
	int j;
	for(j=1;j<=g.vernum;j++)
		visit[j]=0;
	for(j=1;j<=g.vernum;j++)
		if(!visit[j])
			DFS(g,j);
}

void DFS(ALGraph g,int vi)
{
	ArcNode *p;
	printf("%c",g.vertax[vi].data);
	visit[vi]=1;
	p=g.vertax[vi].firstarc;
	while(p){
		if(!(visit[p->adj]))
			DFS(g,p->adj);
		p=p->nextarc;
	}
}

void TraverseBFS(ALGraph g)
{
	int i;
	for(i=1;i<=g.vernum;i++)
		visit[i]=0;
	for(i=1;i<=g.vernum;i++)
		if(!visit[i])	
			BFS(g,i);
}

void BFS(ALGraph g,int vi)
{
	Queue *s;
	ArcNode *p;
	int w;
	s=InitQueue();
	printf("%c",g.vertax[vi].data);
	visit[vi]=1;
	InQueue(s,vi);
	while(s->front-s->rear){
		OutQueue(s,&w);
		p=g.vertax[w].firstarc;
		while(p){
			if(!visit[p->adj]){
				printf("%c",g.vertax[p->adj].data);
				visit[p->adj]=1;
				InQueue(s,p->adj);
			}
			p=p->nextarc;
		}
	}
}

