#include <stdio.h>
#include <stdlib.h>

void file_operation(){

	FILE *fp;
	fp = fopen("input.txt", "w");
	if(fp == NULL){
		printf("Cannot open file. Exit\n");
		exit(1);
	}
	fprintf(fp, "%s\n", "yangfeifei");// output information to fp
	fclose(fp);
}

void input(){

	char username[30];
	char password[30];
	FILE *fp;
	fp = fopen("input.txt", "r");
	if(fp == NULL){
		printf("Cannot open file. Exit\n");
		exit(1);
	}
	fscanf(fp, "%s %s", username, password);
	printf("%s %s\n", username, password);
	fclose(fp);
}

int main(){
	//file_operation();
	input();
	return 0;
}