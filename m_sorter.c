#include "sorter.h"

struct item_t *items[9];
//extern void sort(struct item_t *arr[], int lo, int hi, int meta);

int main(int argc, char *argv[]) {


	for(int i=0; i < 10; i++){
		items[i] = calloc(1, sizeof(struct item_t));
	}
	strcpy(items[0]->duration, "210");
	strcpy(items[1]->duration, "999");
	strcpy(items[2]->duration, "55");
	strcpy(items[3]->duration, "10");
	strcpy(items[4]->duration, "180");
	strcpy(items[5]->duration, "145");
	strcpy(items[6]->duration, "99");
	strcpy(items[7]->duration, "210");
	strcpy(items[8]->duration, "45");


	for(int i=0; i < 9; i++){
		printf("%s\n", items[i]->duration);
	}
	printf("\ngeh\n\n");
	sort(items, 0, 8, 4);

	for(int i=0; i < 9; i++){
		printf("%s\n", items[i]->duration);
	}
	return 0;
}

