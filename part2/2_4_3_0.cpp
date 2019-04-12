#include<iostream>

using namespace std;
unsigned int NumberOf1(int n){
	unsigned int count = 0;
	while(n){
		if(n&1){
			count++;
		}
		n = n >> 1;
	}
	return count;
}


unsigned int NumberOf2(int n){
	int count = 0;
	unsigned int flag = 1;
	while(flag){
		if(n&flag){
			count++;
		}	
		flag = flag << 1;
	}
	return count;
}

unsigned int NumberOf3(int n){
	int count = 0;

}

int main(){
	cout << NumberOf1(5) << endl;
	cout << NumberOf2(10) << endl;
	return 0;
}
