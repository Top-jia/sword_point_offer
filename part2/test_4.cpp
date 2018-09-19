#include<iostream>
#include<stdio.h>
#include<string.h>

#define BUFF_SIZE	127
#define STR			"%20"
int  main(){
	char buffer[BUFF_SIZE];
	memset(buffer, '\0', BUFF_SIZE);
	fgets(buffer, BUFF_SIZE, stdin);
	buffer[strlen(buffer)-1] = '\0';
	int blank = 0;
	int len_blank = 0;
	for(int i = 0; i < strlen(buffer); i++){
		if(buffer[i] == '#'){
			blank++;
		}
		else{
			len_blank++;
		}
	}

	int len = len_blank + blank*strlen(STR)-1;
	int p_len = strlen(buffer)-1;
	while(len >= 0){
		if(buffer[p_len] == '#'){
			buffer[len--] = '0';
			buffer[len--] = '2';
			buffer[len--] = '%';
			p_len--;
		}
		else{
			buffer[len--] = buffer[p_len--];
		}
	}

	printf("buffer = %s\n", buffer);
	return 0;
}
