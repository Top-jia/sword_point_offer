#include<iostream>
#include<vector>

/*
 *	在一个二维数组中, 每一行都按照从左至右递增的顺序排序
 *,每一行都按照从上到下递增的顺序排序, 请输入一个二维数组
 *和一个整数, 判断数组中是否含有该整数.
 *
 *
 * 1	2	3	4
 * 2	4	6	12
 * 4	7	10	13
 * 6	8	11	15
 * 找7 true
 * 	   false
 * */

bool my_find(std::vector<std::vector<int>> &array, int value){
	std::vector<std::vector<int>>::iterator it = array.begin();
	for(; it != array.end(); ++it){
		std::vector<int>::iterator it_point = it->begin();
		for(; it_point != it->end(); ++it_point){
			std::cout << *it_point << "\t";
		}
	}
	return true;
}

int main(){
	std::vector<std::vector<int>> array_double = {\
			{1, 2, 3, 4},						\
			{2, 4, 6, 12},						\
			{4, 7, 10, 13},						\
			{6, 8, 11, 15}						\
												 };
	int elem = 0;
	while(std::cin >> elem){
		bool flag = my_find(array_double, elem);
		std::cout << "look for " << elem << " " << flag << std::endl;
		elem = 0;
	}

	return 0;
}
