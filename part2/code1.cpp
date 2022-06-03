#include <iostream>

bool find(int *matrix, int rows, int columns, int number){
	bool is_exist = false;
	if(NULL != matrix && rows > 0 && columns > 0){
		int i = 0;
		int j = columns - 1;
		while(i < rows && j >= 0){
			if(number == matrix[i * columns + j]){
				is_exist = true;
				break;
			}else if(number > matrix[i * columns + j]){
				i++;
			}else{
				j--;
			}
		}
	}
	return is_exist;
}

bool findRows(int *matrix, int rows, int columns, int number){
	bool is_exist = false;
	if(NULL != matrix && rows > 0 && columns > 0){
		int i = rows -1;
		int j = 0;
		while(i >= 0 && j < columns){
			if(number == matrix[i * columns + j]){
				is_exist = true;
				break;	
			}else if(number > matrix[i * columns + j]){
				j++;
			}else{
				i--;
			}

		}
	}
	return is_exist;
}

int main(){
	int matrix[] = {
			1, 5, 7, 9,
			2, 6, 8, 10,
			7, 9, 10, 12 
	};
	
	for(int i = -10; i < 20; i++){
		bool is_exist = find(matrix, 3, 4, i);
		std::cout << "is find: " << i << ":  "<< is_exist << std::endl;
		is_exist = find(matrix, 3, 4, i);
		std::cout << "is findRows: " << i << ":  "<< is_exist << std::endl;
	}
	return 0;
}
