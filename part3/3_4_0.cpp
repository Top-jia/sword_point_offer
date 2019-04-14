#include<iostream>
using namespace std;

typedef struct single_list{
	struct single_list *next;
	int elem;
}Slist;


typedef struct single_head{
		Slist *root;
	
		Slist* createSlist(int *arrry, int len);
		Slist* lookForBackK(unsigned int k);
		bool isLoopSlist();
		bool reverseSlist();
		void printSlist();
		void tailInsert(Slist **ptr, Slist *jj);
		Slist* operator+(const single_head &src);
	private:
		Slist *allocSlist();
		
}Shead;

/*申请单链表*/
Slist* Shead::allocSlist(){
	Slist *tmp = new Slist();
	return tmp;
}

/*创建单链表*/
Slist* Shead::createSlist(int *array, int len){
	if(!array || len <= 0){
		return NULL;
	}
	
	Slist *tmpInit = allocSlist();
	tmpInit->elem = array[0];
	for(int i = 1; i < len; i++){
		Slist *tmp = allocSlist();
		tmp->elem = array[i];
		tmp->next = tmpInit->next;
		tmpInit->next = tmp;
	}
	return tmpInit;
}

/*寻找倒数第K个指针位置*/
Slist *Shead::lookForBackK(unsigned int k){
	if(k == 0 || !root){
		return NULL;
	}

	Slist *tmp = root;
	Slist *tmp_ptr = root;
	for(int i = 0; i < k - 1; i++){
		tmp = tmp->next;
		if(tmp == NULL){
			return NULL;
		}
	}

	while(tmp->next != NULL){
		tmp = tmp->next;
		tmp_ptr = tmp->next;
	}
	return tmp_ptr;
}

/*判断单链表是否有环*/
bool Shead::isLoopSlist(){
	if(!root || !root->next){
		return false;
	}
	
	bool flag = false;
	Slist *slow = root;
	Slist *fast = root->next;
	while(slow && fast){
		slow = slow->next;
		fast = fast->next;
		if(fast != NULL){
			fast = fast->next;
		}
		if(slow == fast){
			flag = true;
			break;
		}
	}
	return flag;
}

/*将单链表进行翻转*/
bool Shead::reverseSlist(){
	if(!root || !root->next){
		return false;
	}
}

/*将单链表进行打印*/
void Shead::printSlist(){
	Slist *ptr = root;
	while(ptr){
		cout << ptr->elem << " ";
		ptr = ptr->next;
	}
	cout << "\t";
}

/*对单链表进行尾插*/
void Shead::tailInsert(Slist **ptr, Slist *tail){
	if(!ptr || !tail){
		return ;
	}

	if(*ptr == NULL)
	{
		*ptr = tail;
	}else{
		Slist *tmp = *ptr;
		while(tmp->next){
			tmp = tmp->next;
		}
		tmp->next = tail;
	}

}

/*将单链表进行合并*/
Slist* Shead::operator+(const Shead &src){
	if(!root || !src.root){
		return NULL;
	}

	Slist *tmp = NULL;
	Slist *ptrSrc = src.root;
	Slist *ptrDst = root;
	while(ptrDst && ptrSrc){

		Slist *tmpPtr = NULL;
		if(ptrDst->elem > ptrSrc->elem){
			tmpPtr = ptrSrc;
			ptrSrc = ptrSrc->next;
			tmpPtr->next = NULL;
			
		}else{
			tmpPtr = ptrDst;
			ptrDst = ptrDst->next;
			tmpPtr->next = NULL;
		}
		tailInsert(&tmp, tmpPtr);
	}

	while(ptrDst){
		Slist *tmpPtr = ptrDst;
		ptrDst = ptrDst->next;
		tailInsert(&tmp, tmpPtr);
	}
	
	while(ptrSrc){
		Slist *tmpPtr = ptrSrc;
		ptrSrc = ptrSrc->next;
		tailInsert(&tmp, tmpPtr);
	}
	return tmp;
}

int main(){
	Shead head;
	int array[] = {1, 3, 7, 8};
	head.root = head.createSlist(array, sizeof(array)/sizeof(array[0]));
	head.printSlist();	
	cout << "isLoopSlist:: " << head.isLoopSlist() << endl;

	Shead newhead;
	int brray[] = {0, 5, 6, 9};
	newhead.root = newhead.createSlist(brray, 4);
	newhead.printSlist();
	Slist *hh = head + newhead;
	
	cout << "new value:" << endl;
	while(hh){
		cout << hh->elem << " ";
		hh = hh->next;
	}
	cout << "\n";
	return 0;
}
