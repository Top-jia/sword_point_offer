#include<iostream>
#include<unistd.h>
#include<string.h>

using namespace std;


bool Increment(char *number, int len){
	bool isOverflow = false;
	int nTakeOver = 0;
	
	for(int i = len - 1; i >= 0; i--){
		int nSum = number[i] - '0' + nTakeOver;
		if(i == len -1){
			nSum++;
		}
		
		if(nSum >= 10){
			if(i == 0){
				isOverflow = true;
			}else{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else{

			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}


/*可以将其用一个栈来对数据进行保存处理:*/
void PrintElem(char *number, int len){
	bool isBeginning0 = true;
	for(int i = 0; i <= len; i++){
		if(isBeginning0 && number[i] != '\0'){
			isBeginning0 = false;
		}
		
		if(!isBeginning0){
			printf("%c", number[i]);
		}
	}
	cout << "\t";
}

void Print1ToMaxOfDigits(int n){
	if(n <= 0){
		return;
	}
	char *number = new char[n+1];
	memset(number, '\0', n+1);
	while(!Increment(number, n)){
		PrintElem(number, n);
	}
	delete []number;
}

int main(){
	Print1ToMaxOfDigits(3);
	return 0;
}
