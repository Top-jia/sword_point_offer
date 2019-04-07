#include<stdio.h>
#include<iostream>
#include<stack>

/*用两个栈实现一个队列*/


using namespace std;

template<typename T>
class CQueue{
	public:
	//	CQueue(void);
	//	~CQueue(void);
	void appendTail(const T &node);
	T deleteHead();

	private:
		stack<T> stack1;
		stack<T> stack2;
};


/*对队列增加元素*/
template<typename T>
void CQueue<T>::appendTail(const T &elem){
	stack1.push(elem);
}

/*对队列删除元素*/
template<typename T>
T CQueue<T>::deleteHead(){
	if(stack2.size() <= 0){
		while(stack1.size() > 0){
			T &data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	
	if(stack2.size() == 0){
		return T();
	}
	T head = stack2.top();
	stack2.pop();
	return head;
}

int main(){
	CQueue<int> value;
	value.appendTail(45);
	value.appendTail(23);
	cout << value.deleteHead() << endl;
	cout << value.deleteHead() << endl;
	cout << value.deleteHead() << endl;
	return 0;
}
