#include<iostream>



template<typename T>
void StackWithMin<T>::push(const T &value){
	m_data.push(value);
	if(m_min.size() == 0 || value < m_min.top()){
		m_min.push(value);
	}
	else{
		m_min.push(m_min.top());
	}
}

template<typename T>
void StackWithMin<T>::pop(){
	assert(m_data.size() > 0 && m_min.size() > 0 );
	m.data.pop();
	m_min.pop();
}

template<typename T>
void StackWithMin<T>::min(){
	assert(m_data.size() > 0 && m_min.size() > 0)
	return m_min.top();
}

int main(){


	return 0;
}
