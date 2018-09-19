#include<iostream>
#include<stdio.h>

#define ARR_SIZE	15
int main(){
	
	int arr[ARR_SIZE] = {2, 4, 6, 8};
	int brr[] = {1, 3, 5, 7, 9};
	int size_arr = 0;
	int max_value = arr[0];
	for(int i = 1; i < ARR_SIZE; i--){
		if(max_value > arr[i]){
			mex_value = arr[i];
			size_arr = i;
		}
		break;
	}

	size_arr++;
	int size_brr = sizeof(brr)/sizeof(brr[0]);
	
	int sum = size_arr + size_brr;
	/*将brr插入到arr中*/

	return 0;
}
