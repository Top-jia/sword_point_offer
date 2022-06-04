#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{
	int 		m_nKey;
	ListNode	*m_pNext;
	ListNode():m_nKey(-1), m_pNext(NULL){}
}LNode;

void AddTail(LNode **pHead, int value){
	ListNode *pNew = new LNode();
	pNew->m_nKey = value;
	
	if(NULL == *pHead){
		*pHead = pNew;
	}else{
		LNode *pNode = *pHead;
		while(NULL != pNode->m_pNext){
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

void RemoveNode(LNode **pHead, int value){
	if(NULL == pHead || NULL == *pHead){
		return ;
	}

	LNode *node = *pHead;
	if(value == node->m_nKey){
		*pHead = node->m_pNext;
		delete node;
	}else{
		while(NULL != node->m_pNext && value != node->m_pNext->m_nKey){
			node = node->m_pNext;
		}
	
		if(NULL != node->m_pNext && value == node->m_pNext->m_nKey){
			LNode *pBackNode = node->m_pNext->m_pNext;
			delete node->m_pNext;
			node->m_pNext = pBackNode;
		}
	}
}

void PrintListReversingly(LNode *pHead){
	if(NULL == pHead){
		return ;
	}

	std::stack<LNode *> stNode;
	LNode *node = pHead;
	while(NULL != node){
		stNode.push(node);
		node = node->m_pNext;
	}
	
	while(!stNode.empty()){
		node = stNode.top();
		std::cout << "elem: " << node->m_nKey << std::endl;
		stNode.pop();
	}
}

void PrintListReversingly1(LNode *pHead){
	if(NULL != pHead){
		if(NULL != pHead->m_pNext){
			PrintListReversingly1(pHead->m_pNext);
		}
		std::cout << "elem: " << pHead->m_nKey << std::endl;
	}
}


void DeleteNode(LNode **pHead, LNode *deleteNode){
	if(NULL == pHead || NULL == *pHead || NULL == deleteNode){
		return ;
	}
	
	if(NULL != deleteNode->m_pNext){
		LNode *node = deleteNode->m_pNext;
		deleteNode->m_pNext = node->m_pNext;
		deleteNode->m_nKey  = node->m_nKey;

		delete node;
		node = NULL;
	}else if(*pHead == deleteNode){
		delete deleteNode;
		*pHead = NULL;
	}else{
		LNode *node = *pHead;
		while(node->m_pNext != deleteNode){
			node = node->m_pNext;
		}
		
		node->m_pNext = NULL;
		delete deleteNode;
		deleteNode = NULL;
	}
}

LNode* FindKthToTail(LNode *pHead, unsigned int k){
	LNode *kRPtr = NULL;
	if(NULL != pHead){
		LNode *m_kRPtr = pHead;
		for(int i = 0; i < k && m_kRPtr != NULL; i++){
			m_kRPtr = m_kRPtr->m_pNext;
		}

		if(m_kRPtr != NULL){
			kRPtr = pHead;
			while(m_kRPtr != NULL){
				m_kRPtr = m_kRPtr->m_pNext;
				kRPtr   = kRPtr->m_pNext;
			}
		}
	}
	return kRPtr;
}

LNode* ReverseList(LNode **pHead){
	if(NULL == pHead || NULL == *pHead || NULL == (*pHead)->m_pNext){
		return *pHead;
	}

	LNode *mNode = *pHead;
	LNode *mNodeBack = *pHead;
	LNode *mNodeFront = NULL;
	while(NULL != mNode){
		LNode *mNext = mNodeBack->m_pNext;
		if(NULL == mNext){
			*pHead 	= mNodeBack;
		}
		mNodeBack->m_pNext = mNodeFront;
		mNode = mNext;
		mNodeFront = mNodeBack;		
	}
	return *pHead;
}

void FreeNode(LNode **pHead){
	if(NULL == pHead || NULL == *pHead){
		return ;
	}
	
	while(NULL != *pHead){
		LNode *node = (*pHead)->m_pNext;
		delete *pHead;
		*pHead = node;
	}
}

int main(){
	LNode *head = NULL;
	for(int i = 0; i < 7; i++){
		AddTail(&head, i);
	}
	PrintListReversingly(head);
	DeleteNode(&head, head->m_pNext);
	PrintListReversingly1(head);
	FreeNode(&head);
	return 0;
}
