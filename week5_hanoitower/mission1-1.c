#include <stdio.h>
#include <stdlib.h>

#define PLATE_MAX 50

struct {
    int length;
    int plates[PLATE_MAX];

} pole[3];

void printTower() {

    int i, j;

    for (i = 0; i < 3; i++) {
        printf("%d : ", i);
        if (pole[i].length == 0) printf("x");
        else {
	        for (j = 0; j < pole[i].length; j++) {
	            printf("%d ", pole[i].plates[j]);
	        }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
	
	int size;
    scanf("%d", &size);

    pole[0].length = size;
    for (int i = 0 ; i < size; i++) {
        printf("pole[0].plates[%d] = %d\n", i, size - i);
        pole[0].plates[i] = size - i;
    }

    pole[1].length = 0;
    pole[2].length = 0;

    printTower();

	return 0;
}
