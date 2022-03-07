#include<stdlib.h>
#include<stdio.h>

int main(int argc, char **argv)
{
	char symbol;
	int count = 0;
	int N = strtol(argv[2], NULL, 10);
	
	if (N < 0){
		perror ("Invalid value of strings");
		return 1;
	}
	
	FILE *file;
	file = fopen(argv[1], "r");

	if (file == NULL){
		perror ("File opening error");
		return 1;
	}

	while((N == 0) || (count < N)){
	
		do {
		symbol = fgetc(file);
		if (symbol == EOF)
			break;
		printf("%c", symbol);
		} while (symbol != '\n');
		
		if(symbol == EOF)
			break;
		count++;
		if(count == N){
			getc(stdin);
			count = 0;
		}
	}

	fclose(file);
	return 0;
}


