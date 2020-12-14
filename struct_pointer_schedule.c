#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
//Data 구조체
  char *date; //날짜
  char *time; //시간
  int priority; //중요도
  char *name; //제목
  char *description; //내용
};

// 이렇게 할 수 없음!
//char *format_date(char *date){
//
//  char new_date[9];
//
//  if (sizeof(date) != 6) {
//    printf("invalid date\n");
//	exit(1);
//  }
//  return new_date;
//}

int main() {
  int n; //입력받을 데이터의 수
  scanf("%d", &n);

  struct Data ds[n]; //구조체 Data 배열 ds를 n개 생성

  for (int i = 0; i < n; i++) { //데이터 입력
	
	//임시로 사용할 포인터 초기화
  	char *da = (char *)malloc(sizeof(char) * 8);
  	char *ti = (char *)malloc(sizeof(char) * 4);
  	int pr;
  	char *na = (char *)malloc(sizeof(char) * 127);
  	char *de = (char *)malloc(sizeof(char) * 127);

    //임시 변수 입력 받기
  	scanf("%s %s %d %s %s", da, ti, &pr, na, de);

    if (strlen(da) != 8) { //입력받은 날짜는 문자 수가 8개여야 함
		printf("invalid date\n");
		return 0;
    } else {

		char new_date[12]; //새로운 형식의 날짜는 .과 \0을 포함해서 12칸
		for (int i = 0; i < 4; i++) { //년 YYYY 입력
			new_date[i] = da[i]; 
		}
		new_date[4] = '.';


		for (int i = 4; i < 6; i++) { //월 MM 입력
			new_date[i+1] = da[i];
		}
		new_date[7] = '.';


		for (int i = 6; i < 8; i++) { //일 DD 입력
			new_date[i+2] = da[i];
		}
		new_date[10] = '.';

		new_date[11] = '\0'; //문자열 종료

		printf("new_date : %s\n", new_date);
  		ds[i].date = (char *)malloc(sizeof(char) * 8); //구조체에 새로운 형식의 날짜 저장
  		strcpy(ds[i].date, new_date);
    }


    
    if (strlen(ti) != 4) { //입력받은 시간은 문자 수가 4개여야 함
		printf("invalid time\n");
		return 0;
    } else {

		char new_time[6]; //새로운 형식의 시간은 :와 \0을 포함해서 6칸
		for (int i = 0; i < 2; i++) { //시 HH 입력
			new_time[i] = ti[i];
		}
		new_time[2] = ':';

		for (int i = 3; i < 5; i++) { //분 MM 입력
			new_time[i+1] = ti[i];
		}
		new_time[5] = '\0'; //문자열 종료

		printf("new_time : %s\n", new_time);
  		ds[i].time = (char *)malloc(sizeof(char) * 4); //구조체에 새로운 형식의 시간 저장
  		strcpy(ds[i].time, new_time);
    }

    if (pr < 1 || pr > 10) { //입력받은 중요도는 1부터 10까지
		printf("invalid priority\n");
		return 0;
	} else {
  		ds[i].priority = pr;
	}

	if (strlen(na) > 127) { //입력받은 이름은 127자보다 작아야 함
		printf("invalid name\n");
		return 0;
	} else {
  		ds[i].name = (char *)malloc(sizeof(char) * 127); 
  		strcpy(ds[i].name, na);
	}

	if (strlen(de) > 127) { //입력받은 설명은 127자보다 작아야 함
		printf("invalid description\n");
		return 0;
	} else {
  		ds[i].description = (char *)malloc(sizeof(char) * 127); 
  		strcpy(ds[i].description, de);
	}
	
    // 임시로 사용했던 포인터 해제
    free(da);
    free(ti);
    free(na);
    free(de);
  }

  for (int i = 0; i < n; i++) {
  // 데이터 배열 모두 출력

    printf("Data %d : %s %s %d %s %s\n", i+1, ds[i].date, ds[i].time, ds[i].priority, ds[i].name, ds[i].description);;

  }

  
  for (int i = 0; i < n; i++) {
  //입력에 사용했던 구조체 포인터 모두 해제
	free(ds[i].date);
	free(ds[i].time);
	free(ds[i].name);
	free(ds[i].description);

  }

  return 0;
}
