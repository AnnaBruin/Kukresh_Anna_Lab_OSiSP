#include<stdio.h>
#include<dirent.h>

int dir(char const *name){
	int i=1;
	DIR *dp = opendir(name);

	if(!name){
		perror("Error: problems with opening");
		return 1;
	}

	struct dirent *d;
	while (d = readdir(dp)){
		printf("%3d.\t%s\n", i++, d->d_name);
	}
	
	closedir(dp);
}

int main(int argc, char const *argv[]){
	printf("Current directories: \n");
	dir("./");
	printf("Root directories: \n");
	dir("/");
	return 0;
}


