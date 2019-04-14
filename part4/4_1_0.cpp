#include<iostream>


void MirrorRecursively(Btree *root){
	if((root == NULL) || (root->lchild == NULL && root->rchild == NULL){
		return ;
	}

	Btree *tmp = root->lchild;
	root->rchild = root->lchild;
	root->lchild = tmp;
	
	if(root->lchild){
		MirrorRecursively(root->lchild);
	}
	if(root->rchild){
		MirroeRecursively(root->rchild);
	}
}

int main(){
	return 0;
}
