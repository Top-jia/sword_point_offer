#include<iostream>

using namespace std;

bool equal(double num1, double num2){
	if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001)){
		return true;
	}
	else{
		return false;
	}
}

double PowerWithUnsignedExp(double base, unsigned int exp){
	double result = 1.0;
	for(int i = 0; i < exp; i++){
		result *= base;
	}
	return result;
}

bool gInvalidInput = false;
double Power(double base, int exp){
	gInvalidInput = false;
	if(equal(base, 0.0) && exp < 0){
		gInvalidInput = true;
		return 	0.0;
	}

	unsigned int absExp = (unsigned int)exp;
	if(exp < 0){
		absExp = (unsigned int)(-exp);
	}
	
	double result = PowerWithUnsignedExp(base, absExp);
	if(exp < 0){
		return 1.0/result;
	}
	return result;
}


double PowerWithUnsigned(double base, unsigned int exp){
	if(exp == 0){
		return 1;
	}
	if(exp == 1){
		return base;
	}

	double result = PowerWithUnsigned(base, exp>>1);
	result *= result;
	if(exp & 0x1 == 1){
		result *= base;
	}
	return result;
}

int main(){
	cout << Power(12.23, 2) << endl;
	return 0;
}
