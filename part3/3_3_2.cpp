#include<iostream>
#include<string.h>

using namespace std;

void PrintNumber(char *number, int len){
	bool isBeginning = true;
	for(int i = 0;  i < len; i++){
		if(isBeginning && number[i] != '0'){
			isBeginning = false;
		}

		if(!isBeginning){
			cout << number[i];
		}
	}
	cout << "\t";
}

void Print1ToMaxRecursively(char *number, int n, int index){
	if(index == n - 1){
		PrintNumber(number, n);
		return;
	}
	
	for(int i = 0; i < 10; ++i){
		number[index+1] = i + '0';
		Print1ToMaxRecursively(number, n, index + 1);
	}
}

void Print1ToMaxOfDigits(int n){
	if(n <= 0){
		return;
	}
	
	char *number = new char[n+1];
	
	for(int i = 0; i < 10; i++){
		number[0] = i + '0';
		Print1ToMaxRecursively(number, n, i);
	}
}


int main(){
	Print1ToMaxOfDigits(2);
	return 0;
}
