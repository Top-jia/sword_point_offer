#include<iostream>
#include<vector>

/*
 *	在一个二维数组中, 每一行都按照从左至右递增的顺序排序
 *,每一行都按照从上到下递增的顺序排序, 请输入一个二维数组
 *和一个整数, 判断数组中是否含有该整数.
 *
 *
 * 1	2	8	9
 * 2	4	9	12
 * 4	7	10	13
 * 6	8	11	15
 * 找7 true
 *     false
 * */
/*通过对迭代器的相关操作, 可以得到其中的数据*/
void print_array(std::vector<std::vector<int>> &array){
	std::vector<std::vector<int>>::iterator it = array.begin();
	for(; it != array.end(); ++it){
		std::vector<int>::iterator it_point = it->begin();
		for(; it_point != it->end(); ++it_point){
			if((it_point - it->begin())%4 == 0){
				std::cout << std::endl;
			}
			std::cout << *it_point << "\t";
		}
	}
}

/*寻找迭代器中的数据*/
bool my_find(std::vector<std::vector<int>> &array, int value){
	std::vector<std::vector<int>>::iterator it = array.begin();
	std::vector<int>::iterator it_point = it->begin();
	int a_size = array.size();
	int b_size = it->size();
	int rows = 0;
	int column = b_size - 1;
	while(rows < a_size && column >= 0){
		if(array[rows*column][column] == value){
			return true;
		}
		else if(array[rows*column][column] > value){
			--column;
		}
		else{
			rows++;
		}
	}
	return false;
}

int main(){
	std::vector<std::vector<int>> array_double = {\
			{1, 2, 8, 9},						\
			{2, 4, 9, 12},						\
			{4, 7, 10, 13},						\
			{6, 8, 11, 15}						\
												};
	print_array(array_double);
	int elem = 0;
	while(std::cin >> elem){
		bool flag = my_find(array_double, elem);
		std::cout << "look for " << elem << " " << flag << std::endl;
		elem = 0;
	}

	return 0;
}
