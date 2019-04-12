#include<iostream>
using namespace std;
/*
	0   1   1   2   3    5    8


*/
long Fibonacci(int value){
	if(value <= 0){
		return 0;
	}
	if(value == 1){
		return 1;
	}
	return Fibonacci(value-1) + Fibonacci(value-2);
}

long NotFibonacci(int value){
	long result[] = {0, 1};
	if(value < 2){
		return result[value];
	}
	
	long f1 = 0;
	long f2 = 1;
	long max = f1 + f2;
	for(int i = 2; i <= value; i++){
		max = f1 + f2;
		f1 = f2;
		f2 = max;
	}
	return max;
}

int main(){
	int value = 0;
	cout << "please input Fibonacci() value" << endl;
	while(cin >> value){
		cout << "Recursive:" << Fibonacci(value) << endl;
		cout << "not Recursive: " << NotFibonacci(value) << endl;
		cout << "please input Fibonacci() value" << endl;
	}
	return 0;
}
