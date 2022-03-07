#include<stdio.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char **argv)
{
	FILE *file1, *file2;
	struct stat buff;
	char symbol;
	
	file1 = fopen(argv[1], "r+");
	if (file1 == NULL){
		perror ("Сopy file not opening ");
		return 1;
	}
	file2 = fopen(argv[2], "w+");
	if (file2 == NULL){
		perror ("Writable file not opening ");
		return 2;
		fclose(file1);
	}
	
	stat(argv[1], &buff);
	chmod(argv[2], buff.st_mode);

	while((symbol=getc(file1))!=EOF){
		putc(symbol, file2);
	}
	
	fclose(file1);
	fclose(file2);
	return 0;
}


