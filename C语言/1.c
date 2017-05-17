#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
	char data;
	struct node *leftchild;
	struct node *rightchild;
}BiNode,*BiTree;
void CreateTree(BiTree *root);

void PathTree(BiTree root,char Path[],int len);

int main(void)
{
	BiNode *root;
	char Path[100];
	CreateTree(&root);
	PathTree(root,Path,0);	 
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

void PathTree(BiTree root,char Path[],int len)
{
	int i;
	if(root){
		if(root->leftchild==NULL&&root->rightchild==NULL){
			printf("%c:",root->data);
			for(i=0;i<len;i++)
				printf("%c",Path[i]);
			printf("\n");
		}
		else{
			Path[len]=root->data;
			PathTree(root->leftchild,Path,len+1);
			PathTree(root->rightchild,Path,len+1);
		} 
	}
}



