#include<iostream>
#include<deque>

/*用两个队列实现一个栈*/
using namespace std;

template<typename T>
class CStack{

	public:
		void appendHead(const T &);
		T deleteHead();
	private:
		deque<T> deque1;
		deque<T> deque2;
};

/*对栈进行push操作*/
template<typename T>
void CStack<T>::appendHead(const T &value){
	if(deque1.empty() && deque2.empty()){
		deque1.push_front(value);
	}else if(!deque1.empty()){
		deque1.push_front(value);
	}else{
		deque2.push_front(value);
	}
}

/*对栈进行pop操作*/
template<typename T>
T CStack<T>::deleteHead(){
	if(deque1.empty() && deque2.empty()){
		return T();
	}
	else if(deque1.empty()){
		int num = deque2.size();
		while(num > 1){
			T val = deque2.back();
			deque1.push_front(val);
			deque2.pop_back();
			num--;
		}

		T ret = deque2.back();
		deque2.pop_back();
		return ret;
	}else {
		int num = deque1.size();
		while(num > 1){
			T val = deque1.back();
			deque2.push_front(val);
			deque1.pop_back();
			num--;
		}
	
		T ret = deque1.back();
		deque1.pop_back();
		return ret;
	}
}

int main(){
	CStack<int> cs;
	cs.appendHead(1);
	cs.appendHead(2);
	cs.appendHead(3);

	cout << cs.deleteHead() << endl;
	cout << cs.deleteHead() << endl;
	cout << cs.deleteHead() << endl;
	cout << cs.deleteHead() << endl;
	return 0;
}
