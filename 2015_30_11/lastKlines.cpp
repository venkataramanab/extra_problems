#pragma warning(disable:4996);
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int line_count(char *fileName);
void last_k_lines(char * fileName, int k_lines);
void last_k_lines(char * fileName, int k_lines)
{
	k_lines = line_count(fileName) - k_lines;
	if (k_lines <= 0){
		printf("\nINVALID INPUT");
	}
	else{
		FILE * FilePtr = fopen(fileName, "r");
		int temp = 0;
		while ((!feof(FilePtr)) && (temp <= k_lines))
		{
			if (getc(FilePtr) == '\n'){
				temp++;
			}
		}
		while (!feof(FilePtr)){
			printf("%c", getc(FilePtr));
		}
		fclose(FilePtr);
	}
}
int line_count(char *fileName){
	int line_count = 0;
	FILE * file = fopen(fileName, "r");
	while (!feof(file))
	{
		if (getc(file) == '\n'){
			line_count++;
		}
	}
	fclose(file);
	return line_count;
}
void main(){
	char *fileName = (char*)malloc(sizeof(char)* 10);
	int k_lines;
	printf("\nenter file name:");
	scanf("%s", fileName);
	printf("\nenter number lines to be print from last:");
	scanf("%d", &k_lines);
	last_k_lines(fileName,k_lines);
	_getch();
}