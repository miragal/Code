//��ͷ��� 
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
	printf("������ڵ������");
	scanf("%d",&n);
	h=CreateLink(n);
	while(1){
		printf("��ѡ��1.ֱ�����  2.����  3.ɾ��  4.�޸�  5.��ѯ  6.���� 7.����  0.�˳�\n");
		scanf("%d",&c);
		switch(c){
			case 1:{
				if(!h)	printf("����Ϊ��!\n");
				else{
					printf("�������������Ϊ:");
					Print(h); 
				} 
			}break;
			case 2:{
				printf("������Ҫ����Ԫ�ص�λ�ã�");
				scanf("%d",&x);
				t=Add(h,x);
				if(!t)	printf("���ʧ��!\n");
				else {
					printf("��Ӻ������Ϊ��\n");
					Print(h);
				} 
			}break;
			case 3:{
				printf("������Ҫɾ����Ԫ�أ�");
				scanf("%d",&x);
				t=Delete(h,x);
				if(!t)	printf("ɾ��ʧ��!\n");
				else {
					printf("ɾ���������Ϊ��\n");
					Print(h);
				} 
			}break;
			case 4:{
				printf("������Ҫ�޸ĵ�Ԫ�أ�");
				scanf("%d",&x);	
				t=Change(h,x);
				if(!t)	printf("δ�ҵ�!\n");
				else {
					printf("�޸ĺ������Ϊ��\n");
					Print(h);
				} 
			}break;
			case 5:{
				printf("������Ҫ���ҵ�Ԫ�أ�");
				scanf("%d",&x);
				p=Find(h,x);
				if(!p)	printf("δ�ҵ�!\n");
				else printf("�ɹ��ҵ�%d!\n",p->data);
			}break;
			case 6:{
				p=Sort(h);
				printf("��������������Ϊ��"); 
				Print(p);
			}break;
			case 7:{
				Reverse(h);
				printf("���ú������Ϊ��\n");
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
	printf("������ڵ�ֵ(���ظ�):"); 
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
	printf("��ӵ�Ԫ��Ϊ��");
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
		printf("��������ֵ��");
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
//ÿ���ҵ����ģ�ͷ����һ���������� 
LinkNode *Sort(LinkNode *h)
{
	LinkNode *p,*q,*t,*m,*hn=NULL,*x;
	p=h;
	while(p->next){
		m=p;
		for(q=p->next;q->next;q=q->next)
			if(m->next->data<q->next->data)
				m=q;
		//m�����ֵ��ǰ�� 
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
