#include<iostream>
#include<stdio.h>

#define ARR_SIZE	15
int main(){
	
	int arr[ARR_SIZE] = {2, 4, 6, 8, 9};
	int brr[] = {1, 3, 5, 7, 9, 10, 11};
	int size_arr = 0;
	int max_value = arr[0];
	for(int i = 1; i <= ARR_SIZE; i++){
		if(max_value < arr[i]){
			max_value = arr[i];
			size_arr = i;
			continue;
		}
		break;
	}

	int size_brr = sizeof(brr)/sizeof(brr[0]) - 1;
	int size_sum = size_arr + size_brr + 1;
	int size_tmp = size_sum;
	/*将brr插入到arr中*/
	while(size_arr >= 0 && size_brr >= 0){
		if(arr[size_arr] > brr[size_brr]){
			arr[size_sum--] = arr[size_arr--];
		}
		else {
			arr[size_sum--] = brr[size_brr--];
		}
	}
	
	if(size_arr >= 0){
		while(size_arr > -1){
			arr[size_sum--] = arr[size_arr--];
		}
	}
	else if(size_brr >= 0){
		while(size_brr > -1){
			arr[size_sum--] = brr[size_brr--];
		}
	}
	else{
	
	}

	for(int i = 0; i < size_tmp+1; i++){
		printf("arr[%d] = %d\t", i, arr[i]);
		if((i+1) % 4 == 0){
			printf("\n");
		}
	}
	return 0;
}
