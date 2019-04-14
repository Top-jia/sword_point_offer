#include<iostream>
using namespace std;


void RecordOddEver(int *pData, unsigned int length){
	if(!pData || length <= 0){
		return;
	}
	
	int *start = pData;
	int *end = pData + length-1;
	while(start < end){
		/*寻找奇数*/
		while(start < end && (*start & 0x1) != 0){
			start++;
		}
		/*寻找偶数*/
		while(start < end && (*end & 0x1) == 0){
			end--;
		}
		if(start < end){
			int tmp = *start;
			*start = *end;
			*end   = tmp;
		}
	}
}

int main(){

	int array[] = {5, 4, 7, 8, 0, 6, 4, 6, 12, 7};
	RecordOddEver(array, sizeof(array)/sizeof(array[0]));
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++){
		cout << array[i] << " ";
	}
	return 0;
}
