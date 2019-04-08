#include<iostream>
#include<vector>
#include<algoritor>
#include<iterator>

/*把一个数组最开始的若干个元素搬到数组的末尾, 数组的旋转, 输入一个递增排序的数组的一个旋转, 输出旋转的最小元素, */
using namespace std;

int Min(vector<int> &vec){
	int left = 0;
	int right = vec.size() - 1;
	int minIndex = (left + right)/2;
	while(1){
		if(vec[minIndex] > vec[left]){
			left = minIndex;
		}
		
		if(vec[minIndex])

	}

}

int main(){
	int array[] = {6, 7, 8, 9, 10, 11, 1, 2, 3, 5};
	vector<int> vec(array, sizeof(array)/sizeof(array[0]));
	int min = Min(vec);
	cout << "min: " << min << endl;
	return 0;
}	
