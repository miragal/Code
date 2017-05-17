#include <stdio.h>
#include <stdlib.h>
#define Max 20	//��󶥵����
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
	s[start].lowcost=0;//��־����u�Ѽ��뵽����������
	//�Գ��˳�������������ж����ʼ����Ӧ��closedge���� 
	for(i=0;i<g->vexnum;i++){
		if(i-start){
			s[i].adj=start;
			s[i].lowcost=g->arcs[start][i];
		}
	}
	for(e=0;e<g->vexnum-1;e++){  //����ѡ�е�n-1�����������ı� 
		//ѡ����СȨֵ�ı�
		min=N;
		for(k=0;k<g->vexnum;k++){
			if(s[k].lowcost&&s[k].lowcost<min){
				m=k;
				min=s[k].lowcost;
			}
		} 
		s[m].lowcost=0;//��־����v0���뵽���������� 
		//��v0����󣬸���closedge������Ϣ
		for(i=0;i<g->vexnum;i++){
			if(i-m&&g->arcs[m][i]<s[i].lowcost){
				//һ���и�С��Ȩֵ���֣������
				s[i].lowcost=g->arcs[m][i];
				s[i].adj=m; 
			}
		} 
	}
	return s;
}
