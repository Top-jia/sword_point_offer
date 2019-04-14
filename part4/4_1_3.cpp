#include<iostream>


Btree* createBt(char *pre, char *in, int len){
	if(!pre||!in||len <= 0){
		return NULL;
	}
	
	Btree *node = new Btree();
	node->val = *pre;
	
	int rootIndex = 0;
	while(rootIndex < len){
		if(in[rootIndex] == node->val){
			break;
		}
		rootIndex++;
	}

	node->lchild = createBt(pre+1, in, rootIndex);
	node->rchild = createBt(pre+rootIndex+1, in + rootIndex+1, len-rootIndex-1);
	return node;
}

Btree* createBt1(char *post, char *in, int len){
	if(!pre||!in||len <= 0){
		return NULL;
	}
	
	Btree *node = new Btree();
	node->val = post[len-1];
	
	int rootIndex = 0;
	while(rootIndex < len){
		if(node->val == in[rootIndex]){
			break;
		}
		rootIndex++;
	}

	node->lchild = createBt1(post, in, rootIndex);
	node->rchild = createBt1(post+rootIndex, in + rootIndex + 1,  len - (rootIndex + 1));
	return node;
}


void preOrder(Btree *root){
	stack<Btree *>  s;
	Btree *p = root;
	while(p != NULL || !s.empty()){
		while(p!= NULL){
			cout << p->data << " ";
			s.push(p);
			p = p->lchild;
		}
		
		if(!s.empty()){
			p = s.top();
			s.pop();
			p = p->rchild();
		}
	}
}

void inOrder(Btree *root){
	stack<Btree *>  s;
	Btree *p = root;
	while(p != NULL || !s.empty()){
		while(p != NULL){
			s.push(p);
			p = p->lchild;
		}
		
		if(!s.empty()){
			p = s.top();
			cout << p->data << " ";
			s.pop();
			p = p->rchild();
		}

	}
}


/*
	要保证左孩子和右孩子都被已经访问并且左孩子在右孩子访问之前才能访问根节点, 
		@1.对于任一节点p, 将其入栈, 然后沿其左子树一直往下搜索, 直到没有左孩子的节点, 此时该孩子出现在栈顶, 但是此时不能将其
		出站并访问, 因此其右孩子还为被访问, 所以接下来按照相同的规则对其右子树进行相同的处理, 当访问其右子树时, 该节点又出现
		在栈顶, 此时可以将其出站并访问, 就这样, 保证了正确的访问顺序, 可以看出, 在此过程中, 每个节点都出现两次在栈顶, 只有在
		第二次出现在栈顶的时候, 才能访问它, 因此多设置一个变量标示该节点是否第一次出现栈顶.
*/
void postOrder(Btree *root){
	stack<Btree*> st;
	Btree *p = root;
	Btree *tmp = NULL;

	while(p != NULL !st.empty()){
		Btree *btn = (Btree*)

	}

}

/*
	要保证节点在左子树和右子树访问之后才能访问, 因此对于任一点节点P， 现将其入栈, 如果P不存在左右子树, 则可以直接对其进行访问, 或者P存在
	P存在左右子树, 但是其左右子树都已经被访问过, 则同样可以直接访问该节点, 若非上述两种情况, 则将P的右孩子和左孩子依次入栈, 这样保证了每次
	每次取栈顶元素的时候, 左孩子在右孩子前面被访问, 右孩子和左孩子都在更节点前面访问.
*/
void postOrder3(Btree *root){
	stack<Btree *> s;
	Btree *cur;
	Btree *pre;
	s.push(root);
	while(!s.empty()){
		cur = s.top();
		if((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (pre == cur->lchild || pre == cur->rchild))){
			cout << cur->data << " ";
			s.pop();
			pre = cur;
		}
		else{
			if(cur->rchild != NULL){
				s.push(cur->lchild);
			}
			if(cur->lchild != NULL){
				s,push(cur->rchild);
			}
		}

	}
}

int main(){
	return 0;
}
