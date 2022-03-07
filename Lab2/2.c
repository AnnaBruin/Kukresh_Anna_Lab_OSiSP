#include<stdio.h>
#include<string.h>

int main(int argc, char **argv)
{
	int symbol;
	int symbolp;
	FILE *file;
	file = fopen(argv[1], "r+");
	if (file == NULL){
		perror ("File opening error");
		return 1;
	}
	while ((symbolp=getchar()) != '\n'){
		fputc(symbolp, file);
		fputc('\n', file);
		}
	fclose(file);

	FILE *filer;
	filer = fopen(argv[1], "r+");
	if (filer == NULL){
		perror ("File opening error");
		return 2;
	}
	while((symbol=fgetc(filer)) !=EOF){
		printf("%c", symbol);
	}
	fclose(filer);

	return 0;
}


