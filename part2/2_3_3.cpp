#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>

using namespace std;

typedef struct single_list{
	struct single_list *next;
	int elem;
}Slist;

/*申请购买节点*/
Slist* buyNode(){
	Slist *ptr = new Slist();
	return ptr;
}

/*创建一个单链表*/
Slist* createSlist(int *array, int len){
	if(!array || len <= 0){
		return NULL;
	}
	
	Slist *root = buyNode();
	for(int i = 0; i < len; i++){
		Slist *tmp = buyNode();
		tmp->elem = array[i];
		tmp->next = root->next;
		root->next = tmp;
	}
	return root;
}

/*释放一个内存节点*/
void freeSNode(Slist *freeAddr){
	if(!freeAddr){
		free(freeAddr);
	}
}


/*移除某个节点*/
void removeNodeSlist(Slist *head, int value){
	if(!head || !head->next){
		return ;		
	}
	
	Slist *ptr = head->next;
	while(ptr){
		if(ptr->elem == value){
			Slist *ptr_prev = head;
			while(ptr_prev->next != ptr){
				ptr_prev = ptr_prev->next;
			}
			if(head == ptr_prev){
				head->next = ptr->next;
				Slist *tmp = ptr->next;
				freeSNode(ptr);
				ptr = tmp;
			}else{
				Slist *tmp = ptr->next;
				ptr_prev->next = ptr->next;
				freeSNode(ptr);
				ptr = tmp;
			}
			continue;
		}else{
			ptr = ptr->next;
		}
	}
}

/*从头到尾打印元素: 使用栈来进行操作*/
void PrintListReversingly(Slist *root){
	if(!root || !root->next){
		return;
	}
	stack<Slist*> st;
	Slist *ptr = root->next;
	while(ptr){
		st.push(ptr);
		ptr = ptr->next;
	}

	while(!st.empty()){
		Slist *curNode = st.top();
		st.pop();
		cout << "elem : " << curNode->elem << endl;
	}
}

/*使用递归来进行操作*/
void PrintListNotReversingly(Slist *root){
	if(!root){
		return ;
	}

	PrintListNotReversingly(root->next);
	cout << "elem : " << root->elem << endl;
}


int main(){
	int array[] = {7, 8, 5, 2, 9, 4, 6, 7};
	Slist *root = createSlist(array, sizeof(array)/sizeof(array[0])); 
	cout << "PrintListReversingly" << endl;
	PrintListReversingly(root);
	removeNodeSlist(root, 7);
	cout << "removeNodeSlist(root, 7)" << endl;
	PrintListNotReversingly(root->next);
	return 0;
}
