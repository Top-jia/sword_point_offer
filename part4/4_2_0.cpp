#include<iostream>


using namespace std;

void FindPath(Btree *root, int sum){
	if(!root){
		return ;
	}

	std::vector<int> path;
	int currentSum = 0;
	findPath(root, sum, path, currentSum);
}

void findPath(Btree *root, int sum, std::vector<int> &path, int &currentSum){
	currentSum += root->elem;
	path.push_back();

	bool isLeft = root->lchild == NULL && root->lchild == NULL;
	if(currentSum == sum && isLeft){
		printf("a path is founf");
		std::vector<int>::iterator iter = path.begin();
		for(; iter != path.end(); ++iter){
			printf("---");
		}
		printf("\n");
	}
	
	if(root->lchild != NULL){
		findPath(root->lchild, sum,  path, currentSum);
	}
	if(root->rchild != NULL){
		findPath(root->rchild, sum, path, currentSum);
	}
	currentSum -=root->data;
	path.pop_back();
}
