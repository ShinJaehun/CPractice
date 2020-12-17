#include <stdio.h>
#define PLATE_MAX 50

int count = 0;

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
				//printf("pole[%d].values[%d] : %d\n", i, j-1, pole[i].values[j-1]);
			}
		}
		printf("\n");
	}
}

int move(int from, int to) {
	if ((pole[to].length > 0 ) && (pole[from].plates[pole[from].length - 1] > pole[to].plates[pole[to].length - 1])) {
		return 0;
	} else if (pole[from].length - 1 < 0) {
		return 0;
	} else {
		pole[to].length++;
		pole[to].plates[pole[to].length - 1] = pole[from].plates[pole[from].length - 1];
		pole[from].length--;
		printTower();
		printf("pole from %d -> pole to %d\n", from, to);
		count++;
	}
	return 1;
}

int checkFinish(int s, int d) {
	if (pole[0].length == 0 && pole[d].length == s) return 1;
	return 0;
}

int solve(int n, int from, int to) {

	if (n == 1) {
		move(from, to);
		return 0;
	} else {
		solve(n-1, from, 3-(from + to));
		move(from, to);
		solve(n-1, 3-(from + to), to);
	}
}

int main() {

	printf("원판의 개수를 입력하세요: ");

	int size;
	scanf("%d", &size);

	printf("옮길 기둥의 번호를 입력하세요: ");
	int dest;
	scanf("%d", &dest);

	pole[0].length = size;
	for (int i = 0 ; i < size; i++) {
		printf("pole[0].plates[%d] = %d\n", i, size - i);
		pole[0].plates[i] = size - i;
	}

	pole[1].length = 0;
	pole[2].length = 0;

	printf("직접 실행은 1번, 자동 실행은 2번을 입력하세요: ");
	int menu;
	scanf("%d", &menu);
		
	printTower();
	printf("start\n");

	if (menu == 1) {

		while(1) {
			int from, to;
			scanf("%d %d", &from, &to);
	
			if (move(from, to)) {
				printTower();
			} else break;

			if (checkFinish(size, dest)) break;
		}
		printf("count : %d\n", count);
	} else if (menu == 2) {


		solve(size, 0, 2);

		printTower();
		printf("finish\n");
		printf("count : %d\n", count);
	} else {
		return 0;
	}


	return 0;
}
