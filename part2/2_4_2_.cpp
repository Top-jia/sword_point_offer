#include<iostream>

using namespace std;

int AddFromToN_Recursive(int n){
	return n <= 0 ? 0 : n + AddFromToN_Recursive(n-1);
}

int AddFromToN_Iterator(int n){
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += i;
	}
	return sum;
}

int main(){
	int sum = AddFromToN_Recursive(5);
	int res = AddFromToN_Iterator(5);
	if(sum == res){
		cout << "== " << endl;
	}else{
		cout << " != " << endl;
	}
	return 0;
}
