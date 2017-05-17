#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Node
{
	char data;
	struct Node *Lchild;
	struct Node *Rchild;
}BiNode,*Bitree;

typedef struct
{
	Bitree data[MAX];
	int rear,front;
}Queue;

void InitQueue(Queue *q)
{
	q->front=q->rear=-1;
}

void InQueue(Queue *q,Bitree x)
{
	if((q->rear+1)%MAX==q->front)
		printf("¶ÓÂú");
	else
	{
		q->rear=(q->rear+1)%MAX;
		q->data[q->rear]=x;
	}
}

void OutQueue(Queue *q,Bitree *x)
{
	if(q->rear==q->front)
		printf("¶Ó¿Õ");
	else
	{
		q->front=(q->front+1)%MAX;
		*x=q->data[q->front];
	}
}

int EmptyQueue(Queue *q)
{
	if(q->rear==q->front)
		return 1;
	else
		return 0;
}

void Level(Bitree root)
{
	Queue *q;
	Bitree p;
	p=root;
	q=(Queue *)malloc(sizeof(Queue)); 
	InitQueue(q);
	InQueue(q,p);
	while(!EmptyQueue(q))
	{
		OutQueue(q,&p);
		printf("%c",p->data);
		if(p->Lchild!=NULL)
			InQueue(q,p->Lchild);
		if(p->Rchild!=NULL)
			InQueue(q,p->Rchild);
	}
} 


void CreatBitree(Bitree *root)
{
	char ch;
	ch=getchar();
	if(ch=='#')  *root=NULL;
	else
	{
		*root=(Bitree)malloc(sizeof(BiNode));
		(*root)->data=ch;
		CreatBitree(&((*root)->Lchild));
		CreatBitree(&((*root)->Rchild));
	}
}


int main()
{
	Bitree root=NULL;
	CreatBitree(&root);	
	Level(root);
	return 0;
} 

