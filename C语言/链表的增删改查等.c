//带头结点 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}LinkNode;

LinkNode *CreateLink(int n);

int Add(LinkNode *h,int x);

int Delete(LinkNode *h,int x);

int Change(LinkNode *h,int x);

LinkNode *Find(LinkNode *h,int x);

void Reverse(LinkNode *h);

LinkNode *Sort(LinkNode *h);

void Print(LinkNode *h);

int main(void)
{
	int n,c,x,t;
	LinkNode *h,*p;
	printf("请输入节点个数：");
	scanf("%d",&n);
	h=CreateLink(n);
	while(1){
		printf("请选择：1.直接输出  2.增加  3.删除  4.修改  5.查询  6.排序 7.逆置  0.退出\n");
		scanf("%d",&c);
		switch(c){
			case 1:{
				if(!h)	printf("链表为空!\n");
				else{
					printf("该链表的数据域为:");
					Print(h); 
				} 
			}break;
			case 2:{
				printf("请输入要增加元素的位置：");
				scanf("%d",&x);
				t=Add(h,x);
				if(!t)	printf("添加失败!\n");
				else {
					printf("添加后的链表为：\n");
					Print(h);
				} 
			}break;
			case 3:{
				printf("请输入要删除的元素：");
				scanf("%d",&x);
				t=Delete(h,x);
				if(!t)	printf("删除失败!\n");
				else {
					printf("删除后的链表为：\n");
					Print(h);
				} 
			}break;
			case 4:{
				printf("请输入要修改的元素：");
				scanf("%d",&x);	
				t=Change(h,x);
				if(!t)	printf("未找到!\n");
				else {
					printf("修改后的链表为：\n");
					Print(h);
				} 
			}break;
			case 5:{
				printf("请输入要查找的元素：");
				scanf("%d",&x);
				p=Find(h,x);
				if(!p)	printf("未找到!\n");
				else printf("成功找到%d!\n",p->data);
			}break;
			case 6:{
				p=Sort(h);
				printf("升序排序后的链表为："); 
				Print(p);
			}break;
			case 7:{
				Reverse(h);
				printf("逆置后的链表为：\n");
				Print(h);
			}break;
			default: return 0;
		}
	}
	return 0;
}

LinkNode *CreateLink(int n)
{	
	int i,x;
	LinkNode *h,*t,*p;
	h=(LinkNode *)malloc(sizeof(LinkNode));
	h->next=NULL;
	t=h;
	printf("请输入节点值(不重复):"); 
	for(i=0;i<n;i++){
		scanf("%d",&x);
		p=(LinkNode *)malloc(sizeof(LinkNode));
		p->data=x;
		p->next=NULL;
		t=t->next=p;
	}
	return h;
}

int Add(LinkNode *h,int x)
{
	int n,tag=0,i=1;
	LinkNode *newp,*p,*t;
	printf("添加的元素为：");
	scanf("%d",&n);
	newp=(LinkNode *)malloc(sizeof(LinkNode));
	newp->data=n;
	newp->next=NULL;
	for(t=h;t&&x-i;t=t->next,i++);
	if(t){
		newp->next=t->next;
		t->next=newp;
		tag=1;
	}
	return tag; 
}

int Delete(LinkNode *h,int x)
{
	LinkNode *t,*d;
	int tag=0;
	for(t=h;t->next&&t->next->data-x;t=t->next);
	if(t->next){
		d=t->next;
		t->next=d->next;
		free(d);
		tag=1; 
	}
	return tag;
}

int Change(LinkNode *h,int x)
{
	LinkNode *t;
	int n,tag=0;
	for(t=h->next;t&&t->data-x;t=t->next);
	if(t){
		printf("请输入新值：");
		scanf("%d",&n);
		t->data=n;
		tag=1;
	}
	return tag;
}

LinkNode *Find(LinkNode *h,int x)
{
	LinkNode *t;
	for(t=h->next;t&&t->data-x;t=t->next);
	return t;
}

void  Reverse(LinkNode *h)
{
	LinkNode *t,*p;
	t=h->next;
	h->next=NULL;
	while(t){
		p=t->next; 
		t->next=h->next;
		h->next=t;
		t=p;
	} 
}
//每次找到最大的，头插在一个空链表上 
LinkNode *Sort(LinkNode *h)
{
	LinkNode *p,*q,*t,*m,*hn=NULL,*x;
	p=h;
	while(p->next){
		m=p;
		for(q=p->next;q->next;q=q->next)
			if(m->next->data<q->next->data)
				m=q;
		//m是最大值的前驱 
		t=m->next;
		m->next=t->next;
		t->next=hn;
		hn=t;
	}
	x=(LinkNode *)malloc(sizeof(LinkNode));
	x->next=hn;
	hn=x;
	return hn;
	/*
	p=h->next;
	q=p->next;
	while(q){
		if(q->data>p->data){
			p->next=q->next;
			q->next=h->next;
			h->next=q;
			q=p=h;
			q=h->next->next;
		}
		else{
			p=q;
			q=q->next;
		}
	}*/
}

void Print(LinkNode *h)
{
	LinkNode *t;
	for(t=h->next;t;t=t->next)
		printf("%-5d",t->data);
	printf("\n");
}
