#include<stdio.h>
#include<dirent.h>
int main(){
	DIR *dir;
	dir=opendir(".");
	if(dir==NULL){
		printf("Failed to open directory");
		return 1;
	}
	printf("Directory opened successfully");
	closedir(dir);
	return 0;
}
