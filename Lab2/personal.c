#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<errno.h>
#include<limits.h>
#include<libgen.h>

char *Name;

int Finding( FILE *rez, char *name){  
	DIR *dp;                            
	dp = opendir(name);
	
	if(!name){
		perror("Error: problems with opening");
		return 1;
	}
	
	struct dirent *d;   
	struct stat buf;
	char *file = alloca(strlen(name) + NAME_MAX + 2);
	
	if(file==NULL){
		perror("Error: No memory allocated");
		return 1;
	}
	
	long int sum = 0;
	int count = 0;
	int maxsize = -1;  
	char *File = alloca(NAME_MAX); 
	
	if(File==NULL){
		perror("Error: No memory allocated");
		return 1;
	}
	
	File[0] = 0;
	errno = 0;
	while(d = readdir(dp)){
		if(strcmp(".", d->d_name) && strcmp("..", d->d_name)){
			strcpy(file, name);
			strcat(file, "/");
 			strcat(file, d->d_name);
 			
 			if (lstat(file,&buf) == -1) {
				fprintf(stderr,"%s: %s: %s\n", Name, name, strerror(errno));
				return 1;
			}
 			
			if(!S_ISDIR(buf.st_mode)){
				if(buf.st_size > maxsize){
					maxsize = buf.st_size;
					strcpy(File, basename(file));
				}
				sum+=buf.st_size;
				count++;
			}
			if(S_ISDIR(buf.st_mode)){
				Finding(rez, file);
			}
		}
	}

	printf("%s %d %ld %s\n", name, count, sum, File);
	fprintf(rez,"%s %d %ld %s\n", name, count, sum, File);
	closedir(dp);
	return 0;
}

int main(int argc, char **argv){
	Name = alloca(strlen(basename(argv[0])));
	strcpy(Name, basename(argv[0]));

	FILE *file;
	file = fopen(argv[2],"w");
	if (file == NULL){
		perror ("File for rezalt not opening ");
		return 1;
	}

	if(realpath(argv[1], NULL) == NULL) {
		fprintf(stderr,"%s: %s: %s\n", Name, argv[1], strerror(errno));
		return 1;
	}

	Finding(file, realpath(argv[1], NULL));

	fclose(file);
	return 0;
}
