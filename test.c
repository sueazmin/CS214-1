#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
	printf("start\n");

	FILE *fp = fopen("count.txt", "a+");
	/*
	int i, j;
	for(i=0; i < 3; i++){
		for(j=0; j < 3; j++){
			fprintf(fp, "%d %d\n", i, j);
		}
	}
	*/
	fprintf(fp, "lelalms83678628\n");
	pid_t pid = fork();
	fprintf(fp, "%d\n", getpid());
	fclose(fp);
	
	printf("end\n");
	return 0;
}