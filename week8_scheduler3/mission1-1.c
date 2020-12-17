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

void print_data(struct Data d);
void print_datas(struct Data * data, int num_datas);

int main(int argc, char *argv[]) {

	FILE *file_count = fopen("C:\\project\\c\\Schedule\\data.txt", "r"); //자료의 수 알아내기 위해 파일 열기
	
	if (file_count == NULL) { //파일 열기 실패
		printf("파일이 존재하지 않습니다.");
	}
	
	int c = 0;
	int num_datas = 0;
	
	while((c = fgetc(file_count)) != EOF) {
		if (c == '\n') num_datas++;
	}
	num_datas++; //fgetc는 EOF를 만나면 while 루프를 종료해버림 
	
	//  printf("자료의 수는 %d\n", num_datas);
	
	fclose(file_count);
	
	FILE *file = fopen("C:\\project\\c\\Schedule\\data.txt", "r"); //자료를 받아오기 위해 파일 다시 열기
	
	if (file == NULL) { //파일 열기 실패
		printf("파일이 존재하지 않습니다.");
	}

  struct Data *datas = (struct Data *)malloc(sizeof(struct Data) * num_datas); //자료를 저장할 구조체 초기화

  for (int num = 1; num <= num_datas; num++) {

    char *da = (char *)malloc(sizeof(char) * 9); //날짜
    char *ti = (char *)malloc(sizeof(char) * 5); //시간
    int pr; //중요도
    int gr; //그룹
    char *na = (char *)malloc(sizeof(char) * 127); //제목
    char *de = (char *)malloc(sizeof(char) * 127); //설명

    fscanf(file, "%s %s %d %d %s %s", da, ti, &pr, &gr, na, de);
    //printf("%d, %s, %s, %d, %d, %s, %s\n", num, da, ti, pr, gr, na, de);

    datas[num].date = (char *)malloc(sizeof(char) * 9); //날짜
    strcpy(datas[num].date, da);

    datas[num].time = (char *)malloc(sizeof(char) * 5); //시간
    strcpy(datas[num].time, ti);

    datas[num].priority = pr; //중요도
    datas[num].group = gr; //그룹

    datas[num].name = (char *)malloc(sizeof(char) * (strlen(na) + 1)); //제목
    strcpy(datas[num].name, na);

    datas[num].description = (char *)malloc(sizeof(char) * (strlen(de) + 1)); //시간
    strcpy(datas[num].description, de);

//	  여기서 free() 하면 프로그램이 정지되는데 이유는 모르겠어요. 
//    free(da);
//    free(ti);
//    free(na);
//    free(de);

  }

  //출력 
  print_datas(datas, num_datas);
  
  for (int num = 1; num <= num_datas; num++) {
    // 구조체 멤버로 사용했던 포인터 해제
    free(datas[num].date);
    free(datas[num].time);
    free(datas[num].name);
    free(datas[num].description);
  }

//  int count[5] = { 0, 0, 0, 0, 0 }; //그룹 0부터 4까지 자료의 수를 저장할 배열 초기화
//
//  for (int num = 1; num <= numberOfGroups; num++) {
//
//    printf("%d : %s\n", num, dataGroups[num].date);
//    printf("%d : %s\n", num, dataGroups[num].time);
//    printf("%d : %d\n", num, dataGroups[num].group);
//    printf("%d : %d\n", num, dataGroups[num].priority);
//    printf("%d : %s\n", num, dataGroups[num].name);
//    printf("%d : %s\n", num, dataGroups[num].description);
//
//    switch (dataGroups[num].group) { //그룹에 따라 자료의 수 증가
//      case 0:
//        count[0]++;
//        break;
//      case 1:
//        count[1]++;
//        break;
//      case 2:
//        count[2]++;
//        break;
//      case 3:
//        count[3]++;
//        break;
//      case 4:
//        count[4]++;
//        break;
//      default:
//        break;
//    }
//
//    // 구조체 멤버로 사용했던 포인터 해제
//    free(dataGroups[num].date);
//    free(dataGroups[num].time);
//    free(dataGroups[num].name);
//    free(dataGroups[num].description);
//
//  }

  // 구조체 포인터 해제
  free(datas);

//  그룹별 자료의 수 출력
//  for (int i = 0; i < 5; i++) {
//    printf("%d ", count[i]);
//  }
//  printf("\n");

  //파일 닫기
  fclose(file);

  return 0;
}

void print_data(struct Data d) {

	//날짜 출력 
    char new_date[12]; //새로운 형식의 날짜는 .과 \0을 포함해서 12칸
    for (int i = 0; i < 4; i++) { //년 YYYY 입력
        new_date[i] = d.date[i];
    }
    new_date[4] = '.';

    for (int i = 4; i < 6; i++) { //월 MM 입력
        new_date[i+1] = d.date[i];
    }
    new_date[7] = '.';

    for (int i = 6; i < 8; i++) { //일 DD 입력
        new_date[i+2] = d.date[i];
    }
    new_date[10] = '.';

    new_date[11] = '\0'; //문자열 종료

    printf("%s  ", new_date);
	
	//시간 출력 
    char new_time[6]; //새로운 형식의 시간은 :와 \0을 포함해서 6칸
    for (int i = 0; i < 2; i++) { //시 HH 입력
        new_time[i] = d.time[i]; 
    }
    new_time[2] = ':';

    for (int i = 2; i < 4; i++) { //분 MM 입력
        new_time[i+1] = d.time[i];
    }
    new_time[5] = '\0'; //문자열 종료

    printf("%s  ", new_time);

    //중요도 출력
    printf("%d      ", d.priority);
    
	//그룹 출력
    switch (d.group) {
		case 0:
	    	printf("공부 ");
	        break;
	    case 1:
	    	printf("상담 ");
	        break;
	    case 2:
	        printf("약속 ");
	        break;
	    case 3:
	        printf("휴식 ");
	        break;
	    case 4:
	        printf("기타 ");
	        break;
	    default:
	        break;
	}
	
	//제목 출력
    printf("%s  ", d.name);
    
    //내용 출력 
    printf("%s\n", d.description);
	
}
	
void print_datas(struct Data *datas, int num_datas) {
	
	printf("날짜         시간   중요도 그룹 제목      내용\n");

	for (int i = 0; i < 5; i++) {
		//그룹별로 자료 출력하기 
		//printf("%d번 그룹 데이터\n", i);
		for (int num = 1; num <= num_datas; num++) {
			if (datas[num].group == i) { 
				print_data(datas[num]);
			}
		}
	}
}

//void print_datas(struct Data *datas, int num_datas) {
//    for (int num = 1; num <= num_datas; num++) {
//
//		//날짜 출력 
//	    char new_date[12]; //새로운 형식의 날짜는 .과 \0을 포함해서 12칸
//	    for (int i = 0; i < 4; i++) { //년 YYYY 입력
//	        new_date[i] = datas[num].date[i];
//	    }
//	    new_date[4] = '.';
//	
//	    for (int i = 4; i < 6; i++) { //월 MM 입력
//	        new_date[i+1] = datas[num].date[i];
//	    }
//	    new_date[7] = '.';
//	
//	    for (int i = 6; i < 8; i++) { //일 DD 입력
//	        new_date[i+2] = datas[num].date[i];
//	    }
//	    new_date[10] = '.';
//	
//	    new_date[11] = '\0'; //문자열 종료
//	
//	    printf("new_date : %s\n", new_date);
//		
//		//시간 출력 
//	    char new_time[6]; //새로운 형식의 시간은 :와 \0을 포함해서 6칸
//	    for (int i = 0; i < 2; i++) { //시 HH 입력
//	        new_time[i] = datas[num].time[i]; 
//	    }
//	    new_time[2] = ':';
//	
//	    for (int i = 2; i < 4; i++) { //분 MM 입력
//	        new_time[i+1] = datas[num].time[i];
//	    }
//	    new_time[5] = '\0'; //문자열 종료
//	
//	    printf("new_time : %s\n", new_time);
//   
//	    //중요도 출력
//	    printf("priority : %d\n", datas[num].priority);
//	    
//		//그룹 출력
//	    switch (datas[num].group) {
//			case 0:
//		    	printf("group : %s\n", "공부");
//		        break;
//		    case 1:
//		    	printf("group : %s\n", "상담");
//		        break;
//		    case 2:
//		        printf("group : %s\n", "약속");
//		        break;
//		    case 3:
//		        printf("group : %s\n", "휴식");
//		        break;
//		    case 4:
//		        printf("group : %s\n", "기타");
//		        break;
//		    default:
//		        break;
//		}
//		
//		//제목 출력
//	    printf("name : %s\n", datas[num].name);
//	    
//	    //내용 출력 
//	    printf("description : %s\n", datas[num].description);
//
//	}
//}

