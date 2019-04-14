#include<iostream>


void PrintMatrixClockwisely(int **numbers, int columns, int rows){
	if(numbers == NULL || columns <= 0 || rows <= 0){
		return ;
	}
	
	int start = 0;
	while(columns > start * 2 && rows > start * 2){
		PrintMatrixInCircle(numbers, columns, rows, start);
		++start;
	}
}

/*
	第一步:	从左至右.
	第二步: 从上到下.
	第三步: 从右至左.
	第四步: 从下至上.
	
*/
void PrintMatrixInCircle(int **number, int columns, int rows, int rows, int start){
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;
	
	/*从左至右打印一行*/
	for(int i = start; i <= endX; ++i){
		int number = numbers[start][i];
		printNumber(number);
	}

	/*从上到下打印一行*/
	if(start < endY){
		for(int i = start + 1; i <= endY; ++i){
			int number = numbers[i][endY];
			printNumber(number);
		}
	}

	/*从右至左*/
	if(start < endY && start < endY){
		for(int i = endX - 1; i >= start; --i){
			int number = numbers[endY][i];
			printNumber(number);
		}
	}

	/*从上到下*/
	if(start < endX && start < endY - 1){
		for(int i = endY - 1; i >= start + 1; --i){
			int number = numbers[i][start];
			printNumber(number);
		}
	}
}

int main(){

	return 0;
}
