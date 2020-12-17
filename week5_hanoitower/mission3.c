#include <stdio.h>
#include <stdlib.h>

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
		
		printf("pole from %d -> pole to %d\n", from, to);
		printTower();
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
        //원반을 목적지로
        return 0;
    } else {
    //from, to 외에 거쳐야 할 빈 기둥을 3-(from + to)로 표현, 기둥의 종류는 0, 1, 2이므로... 
        solve(n-1, from, 3-(from + to)); //n-1 원반을 빈 기둥으로  
        move(from, to); //n 원반을 목적지로 
        solve(n-1, 3-(from + to), to); //빈 기둥에 있는 n-1 원반을 목적지로 
    }
}

int main(int argc, char *argv[]) {
	printf("원판의 개수를 입력하세요: ");
	int size;
    scanf("%d", &size);
	
	printf("옮길 기둥의 번호를 입력하세요: ");
	int dest;
	scanf("%d", &dest);

    pole[0].length = size;
    for (int i = 0 ; i < size; i++) {
        //printf("pole[0].plates[%d] = %d\n", i, size - i);
        pole[0].plates[i] = size - i;
    }

    pole[1].length = 0;
    pole[2].length = 0;

	printf("직접 실행은 1번, 자동 실행은 2번을 입력하세요: ");
	int menu;
	scanf("%d", &menu);

	printTower();
	printf("시작\n");

	if (menu == 1) {
		//직접 실행 

		while(1) {
			int from, to;
			scanf("%d %d", &from, &to);
	
			if (move(from, to)) {
				if (checkFinish(size, dest)) {
					printf("총%d번이동했습니다!\n", count);
					break;
				}
			} else return 0;
		}
	} else if (menu == 2) {
		//자동 실행 

		solve(size, 0, dest);

		printf("끝\n");
		printf("총 %d번 이동했습니다!\n", count);
	} else {
		return 0;
	}
	return 0;
}
