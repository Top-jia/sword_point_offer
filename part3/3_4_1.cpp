#include<iostream>

bool doesTreeHaveTree2(Btree *root, Btree *rt1){
	if(rt1 == NULL){
		return true;
	}
	if(root == NULL){
		return false;
	}
	
	if(root->elem != rt1->elem){
		return false;
	}

	return doesTreeHaveTree(root->lchild, rt->lchild) && doesTreeHaveTree2(root->rchild, rt1->rchild);
}


bool hasSubtree(Btnode *root, Btnode *rt1){
	bool result = false;
	if(root != NULL && rt1 != NULL){
		if(root->elem == rt1->elem){
			result = doesTreeHaveTree2(root, rt1);
		}
		if(!result){
			result = hasSubTree(root->lchild, rt1);
		}
		if(!result){
			result = hasSubTree(root->rchild, rt1);
		}
	}
	return result;
}


int main(){

	return 0;
}
