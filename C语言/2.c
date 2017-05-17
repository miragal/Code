#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100

typedef struct node
{
	char data;
	struct node *leftchild;
	struct node *rightchild;
}BiNode,*BiTree;

typedef struct queue
{
	int front,rear;
	BiTree data[Max];
}Queue;

void CreateTree(BiTree *root);

int LeafCount(BiTree root);

int Count1(BiTree root);

int Count2(BiTree root);

void PrintLeaf(BiTree root);

int main (void)
{
	BiNode *root;
	CreateTree(&root);
	printf("%d %d %d\n",LeafCount(root),Count1(root),Count2(root));
	PrintLeaf(root);
	return 0;
}

void CreateTree(BiTree *root)
{
	char ch;
	ch=getchar();
	if(ch=='#')	*root=NULL;
	else{
		*root=(BiTree)malloc(sizeof(BiNode));
		(*root)->data=ch;
		CreateTree(&((*root)->leftchild));
		CreateTree(&((*root)->rightchild));
	}
}

int LeafCount(BiTree root)
{
	int rl,nl,n;
	if(!root)	return 0;
	if(root->leftchild==NULL&&root->rightchild==NULL)	return 1;
	nl=LeafCount(root->leftchild);
	rl=LeafCount(root->rightchild);
	return nl+rl;
}

int Count1(BiTree root)
{
	int n=0;
	if(root){
		if(root->leftchild&&root->rightchild==NULL||root->leftchild==NULL&&root->rightchild)
			n=1+Count1(root->leftchild)+Count1(root->rightchild);
		else	n=Count1(root->leftchild)+Count1(root->rightchild);
	}
	return n;
}

int Count2(BiTree root)
{
	int n=0;
	if(root){
		if(root->leftchild&&root->rightchild)
			n=1+Count2(root->leftchild)+Count2(root->rightchild);
		else	n=Count2(root->leftchild)+Count2(root->rightchild);
	}
	return n;
}

void PrintLeaf(BiTree root)
{
	if(root){
		if(root->leftchild==NULL&&root->rightchild==NULL)
			printf("%c",root->data);
		PrintLeaf(root->leftchild);
		PrintLeaf(root->rightchild);
	}
}
