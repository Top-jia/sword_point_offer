#include<algorithm>
#include<iostream>
#include<vector>
#include<iterator>
#include<cstdlib>


/*定义一个随机函数, 来表明一个数在一个一定的范围*/
#define random(x) (rand()%x)
using namespace std;


/*定义雇员数的数量: 和最大最小的雇员年龄*/
const int countEmployee = 10000;
const int maxAge = 100;
const int minAge = 18;

int main(){
	/*将几万个数据存储在vec中*/
	vector<int> vec(countEmployee, 0);
	for(int i = 0; i < countEmployee; i++){
		unsigned int randNum = random(maxAge);
		if(randNum >= minAge){
			vec.insert(vec.begin(), randNum);
		}
	}
	
	/*将其中的数据全部存贮到对应的下表内存中*/
	vector<unsigned int> ageDistribution(maxAge, 0);
	for(int i = 0; i < countEmployee; i++){
		ageDistribution.at(vec[i])++;
	}
	std::copy(ageDistribution.begin() + minAge, ageDistribution.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
