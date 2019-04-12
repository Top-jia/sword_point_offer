#include<iostream>
#include<stdio.h>
#include<string.h>


typedef struct tree_node{
	struct tree_node *lchild;
	struct tree_node *rchild;
	char elem;
} Tnode;

typedef struct binary_tree{
	Tnode *root;
} BTree;


/*给树节点申请节点内存*/
Tnode* buyBNode(){
	Tnode *ptr = new Tnode();
	return ptr;
}

/*构造二叉树*/
Tnode* construct(char *preIndex, char *endPre, char *inIndex, char *endIn){
	if(preIndex == endPre || inIndex == endIn){
		return NULL;
	}
	Tnode *newRoot = buyBNode();
	newRoot->elem = *preIndex;
	char *childIndex = inIndex;
	while(childIndex != endIn && *childIndex != newRoot->elem){
		childIndex++;
	}
	if(*childIndex == newRoot->elem){
		int index = childIndex - inIndex;
		char *newEndPre = preIndex + index;
		if(index > 0){
			newRoot->lchild = construct(preIndex+1, newEndPre, inIndex, childIndex-1);
		}
		if(index < endPre - preIndex){
			newRoot->rchild = construct(newEndPre + 1, endPre, childIndex + 1, endIn);
		}
		return newRoot;
	}
	return NULL;
}



/*构造一个二叉树*/
Tnode* constructBTree(char *preIndex, char *inIndex){
	if(!preIndex||!inIndex||(strlen(preIndex) != strlen(inIndex))||(strlen(preIndex) <= 0)){
		return NULL;
	}
	int len = strlen(preIndex);
	return construct(preIndex, preIndex+len-1, inIndex, inIndex+len-1);
}

using namespace std;

/*打印二叉树: 前序遍历*/
void PrintBTPre(const Tnode *root){
	if(root){
		cout << root->elem << endl;
		PrintBTPre(root->lchild);
		PrintBTPre(root->rchild);
	}
}

int main(){
	char *preIndex = "12473568";
	char *inIndex  = "47215386";
	BTree tree;	
	tree.root = constructBTree(preIndex, inIndex);
	PrintBTPre(tree.root);
	return 0;
}
