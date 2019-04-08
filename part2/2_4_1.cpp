#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

void Sort(vector<int> &vec, int left, int right){
	if(left >= right){
		return ;
	}
	int i = left;
	int j = right;

	int tmp = vec[i];
	while(i != j){
		while(i != j && tmp <= vec[j]){
			j--;
		}
		vec[i] = vec[j];
		while(i != j && tmp > vec[i]){
			i++;
		}
		vec[j] = vec[i];
	}

	vec[i] = tmp;
	int position = i;
	Sort(vec, left, i);
	Sort(vec, i+1, right);
}

void QSort(vector<int> &vec){
	Sort(vec, 0, vec.size()-1);
}


int main(){
	int array[] = {8, 5, 0, 9, 4, 9, 7, 2, 6, 1, 3};
	vector<int> vec;
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++){
		vec.push_back(array[i]);
	}
	
	QSort(vec);
	copy(vec.begin(), vec.end(), ostream_iterator<int>(std::cout, " "));
	cout << endl;
	return 0;
}
