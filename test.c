#include "sorter.h"

void rem_endwhite(char *string){
	int len = strlen(string) -1;
	int i;
	for(i=len; isspace(string[i]) && i > 0; i--){
		string[i] = '\0';
	}
}



int main(){
	printf("start\n");
	
	char lel[40] = "siberian tiger    \r\n\t";
	printf("%s-----\n\n", lel);
	
	rem_endwhite(lel);
	printf("%s-----\n\n", lel);
	
	
	printf("end\n");
	return 0;
}

