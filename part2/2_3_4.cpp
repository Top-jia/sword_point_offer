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
Tnode* construct(const char *preIndex, int startPre, int endPre, const char *inIndex, int startIn, int endIn){
	if(startPre == endPre || startIn == endIn){
		return NULL;
	}
	Tnode *newRoot = buyBNode();
	newRoot->elem = preIndex[startPre];
	int index = 0;
	for(int i = startIn; i <= endIn; i++){
		if(inIndex[i] == preIndex[startPre]){
			index = i;
			break;
		}
	}

	newRoot->lchild = construct(preIndex, startPre+1, startPre+index-startIn, inIndex, startIn, index-1);
	newRoot->rchild = construct(preIndex, index+1, endPre, inIndex, index+1, endIn);
	return newRoot;
}

/*构造一个二叉树*/
Tnode* constructBTree(const char *preIndex, const char *inIndex){
	if(!preIndex||!inIndex||(strlen(preIndex) != strlen(inIndex))||(strlen(preIndex) <= 0)){
		return NULL;
	}
	return construct(preIndex, 0, strlen(preIndex), inIndex, 0, strlen(inIndex));
}

using namespace std;
int main(){
	const char *preIndex = "12473568";
	const char *inIndex  = "47215386";
	BTree tree;	
	tree.root = constructBTree(preIndex, inIndex);
	return 0;
}
