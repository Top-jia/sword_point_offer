#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

/*
 *	主要以解决问题为主, 不考虑c/c++方式.
 * */

void ReplaceBlank(char *string, int length){
	if(NULL != string && length > 0){
		int blankNumber = 0;
		int actualLength = strlen(string);
		int i = 0;
		while(i < actualLength){
			if(' ' == string[i]){
				blankNumber++;
			}
			i++;
		}
		
	
		if(length > (actualLength + blankNumber * 2)){
			char *p_front = &string[actualLength - 1];
			char *p_back  = &string[actualLength - 1 + blankNumber * 2];
			while(p_front != p_back){
				if(' ' == *p_front){
					p_front--;
					*p_back-- = '0';
					*p_back-- = '2';
					*p_back-- = '%';
				}else{
					*p_back-- = *p_front--;
				}
			}
		}
	}
}

int main(){
	char string[30] = {" We  are happy. "};
	ReplaceBlank(string, 30);
	std::cout << "string: "	 << string << std::endl;
	return 0;
}
