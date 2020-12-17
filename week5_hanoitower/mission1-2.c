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

int move(int from, int to) {
	if ((pole[to].length > 0 ) && (pole[from].plates[pole[from].length - 1] > pole[to].plates[pole[to].length - 1])) {
	//옮겨갈 기둥에 원반이 있고 && 옮길 원반이 옮겨갈 기둥의 원반과 비교해서 크다면 
		return 0;
	} else if (pole[from].length - 1 < 0) {
	//옮길 기둥에 원반이 없다면 
		return 0;
	} else {
		pole[to].length++; //옮겨갈 기둥에 원반 추가할 자리 늘리기 
		pole[to].plates[pole[to].length - 1] = pole[from].plates[pole[from].length - 1]; //옮길 기둥의 원반을 올겨갈 기둥의 끝에 복사 
		pole[from].length--; //옮길 기둥의 자리 하나 줄이기 
	}
	return 1;
}

int main(int argc, char *argv[]) {
	
	int size;
    scanf("%d", &size);

    pole[0].length = size;
    for (int i = 0 ; i < size; i++) {
        //printf("pole[0].plates[%d] = %d\n", i, size - i);
        pole[0].plates[i] = size - i;
    }

    pole[1].length = 0;
    pole[2].length = 0;

    printTower();
    
	while(1) {
		int from, to;
		scanf("%d %d", &from, &to);
	
		if (move(from, to)) {
			printTower();
		} else break;
	}
	return 0;
}
