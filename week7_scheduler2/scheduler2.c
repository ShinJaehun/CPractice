#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
//Data 구조체
  char *date; //날짜
  char *time; //시간
  int priority; //중요도
  int group;
  char *name; //제목
  char *description; //내용
};

int main(int argc, char *argv[]) {

  int numberOfGroups = 0; //자료의 수

  FILE *file = fopen("C:\\project\\c\\PointerArray\\input.txt", "r"); //파일 열기

  if (file == NULL) { //파일 열기 실패
    printf("파일이 존재하지 않습니다.\n");
  }

  fscanf(file, "%d", &numberOfGroups); //파일 첫 줄에 있는 일정 수 입력 받기
//  printf("자료의 수는 %d\n", numberOfGroups);

  struct Data *dataGroups = (struct Data *)malloc(sizeof(struct Data) * numberOfGroups); //자료를 저장할 구조체 초기화

  for (int num = 1; num <= numberOfGroups; num++) {

    //파일에서 받아온 임시 자료를 저장할 변수 초기화
    char *da = (char *)malloc(sizeof(char) * 9); //날짜
    char *ti = (char *)malloc(sizeof(char) * 5); //시간
    int pr; //중요도
    int gr; //그룹
    char *na = (char *)malloc(sizeof(char) * 127); //제목
    char *de = (char *)malloc(sizeof(char) * 127); //설명

    fscanf(file, "%s %s %d %d %s %s", da, ti, &pr, &gr, na, de); //파일에서 임시 변수에 자료 받아오기
//    printf("%d, %s, %s, %d, %d, %s, %s\n", num, da, ti, pr, gr, na, de);

    dataGroups[num].date = (char *)malloc(sizeof(char) * 9); //날짜
    strcpy(dataGroups[num].date, da);

    dataGroups[num].time = (char *)malloc(sizeof(char) * 5); //시간
    strcpy(dataGroups[num].time, ti);

    dataGroups[num].priority = pr; //중요도
    dataGroups[num].group = gr; //그룹

    dataGroups[num].name = (char *)malloc(sizeof(char) * (strlen(na) + 1)); //제목
    strcpy(dataGroups[num].name, na);

    dataGroups[num].description = (char *)malloc(sizeof(char) * (strlen(de) + 1)); //시간
    strcpy(dataGroups[num].description, de);

    free(da);
    free(ti);
    free(na);
    free(de);

  }

  int count[5] = { 0, 0, 0, 0, 0 }; //그룹 0부터 4까지 자료의 수를 저장할 배열 초기화

  for (int num = 1; num <= numberOfGroups; num++) {

//    printf("%d : %s\n", num, dataGroups[num].date);
//    printf("%d : %s\n", num, dataGroups[num].time);
//    printf("%d : %d\n", num, dataGroups[num].group);
//    printf("%d : %d\n", num, dataGroups[num].priority);
//    printf("%d : %s\n", num, dataGroups[num].name);
//    printf("%d : %s\n", num, dataGroups[num].description);


    switch (dataGroups[num].group) { //그룹에 따라 자료의 수 증가
      case 0:
        count[0]++;
        break;
      case 1:
        count[1]++;
        break;
      case 2:
        count[2]++;
        break;
      case 3:
        count[3]++;
        break;
      case 4:
        count[4]++;
        break;
      default:
        break;
    }

    // 구조체 멤버로 사용했던 포인터 해제
    free(dataGroups[num].date);
    free(dataGroups[num].time);
    free(dataGroups[num].name);
    free(dataGroups[num].description);

  }

  // 구조체 포인터 해제
  free(dataGroups);

  //그룹별 자료의 수 출력
  for (int i = 0; i < 5; i++) {
    printf("%d ", count[i]);
  }
  printf("\n");

  //파일 닫기
  fclose(file);
  return 0;
}

