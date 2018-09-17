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
		if(array[rows][column] == value){
			return true;
		}
		else if(array[rows][column] > value){
			--column;
		}
		else{
			rows++;
		}
	}
	return false;
}

/*用迭代器进行操作
 *	对于相关的迭代器的使用, 和其中的定义操作熟悉.
 * */
template<typename T>
bool iterator_my_find(std::vector<std::vector<T>> &array, T value){
	typename std::vector<std::vector<T>>::iterator it = array.begin();
	typename std::vector<T>::iterator it_point = it->end() - 1;
	while(it_point != it->begin() && it != array.end()){
		if(*it_point == value){
			return true;
		}
		else if(*it_point > value){
			it_point--;
		}
		else{
			int size = it_point - it->begin();
			it++;
			if(it == array.end()){
				break;
			}
			it_point = it->begin() + size;
		}
	}
	if(*it_point == value){
		return true;
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
		bool flag = iterator_my_find(array_double, elem);
		std::cout << "look for " << elem << " " << flag << std::endl;
		elem = 0;
	}
	
	//iterator_my_find(array_double, 5);
	return 0;
}
