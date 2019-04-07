#include<iostream>

using namespace std;

bool find(int *array, int rows, int columns, int number){
	bool found = false;
	if(array != NULL && rows > 0 && columns > 0){
		int row = 0;
		int column = columns - 1;
		while(row  <= rows && column >= 0){
			if(array[row * columns + column] == number){
				found = true;
				break;
			}else if(array[row * columns + column] > number){
				--column;
			}else
				++row;
		
		}
	}
	return found;
}

int main(){
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	bool judge = find(array, 5, 5, 10);
	cout << "Exits " << judge << endl;
	return 0;
}
