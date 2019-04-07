#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>


using namespace std;
const char *str = "%20";

char *replaceBlack(const char *string){
	if(!string){
		return NULL;
	}
	int blackChar = 0;
	int len = strlen(string);
	/*得到空格字符数*/
	for(int i = 0; i < len; i++){
		if(' ' == string[i]){
			blackChar++;
		}
	}

	int newLen = len - blackChar + strlen(str)*blackChar + 1;
	char *tmp = (char *)malloc(sizeof(char)*newLen);
	bzero(tmp, sizeof(char)*newLen);
	
	int sumIndex = 0;
	int oldStr = 0;
	int insertStr = 0;
	while(sumIndex != newLen){
		while(oldStr <= strlen(string) && string[oldStr] != ' '){
			tmp[sumIndex++] = string[oldStr++];
		}

		if(string[oldStr] == ' '){
			oldStr++;
		}
		
		if(sumIndex < newLen){
			while(insertStr != strlen(str)){
				tmp[sumIndex++] = str[insertStr++];
			}
			insertStr = 0;
		}
	}
	return tmp;
}


int main(){
	const char *string = " hello  world! Tom ";
	char *str = replaceBlack(string);
	cout << "new string : " << str << endl;
	return 0;
}
