#include <stdio.h>
#include <stdlib.h>

char *str_compare(char *s1, char *s2) {
	//s1과 s2 중에 어떤 문자열이 더 긴지 확인(긴 문자열을 기준으로 비교해야 하기 때문) 
	int count_s1 = 0;
	while(s1[count_s1] != '\0') { // s1을 돌면서 카운트를 하나씩 증가시킴 
		count_s1++;
	}
	
	int count_s2 = 0;
	while(s2[count_s2] != '\0') {
		count_s2++;
	}
	
	int i = 0;
	if (count_s1 >= count_s2) { //s1이 더 길다면 
		while(s1[i] != '\0') { //s1 문자열 끝까지 반복 
			if (s1[i] != s2[i]) { //같은 위치의 s1 문자와 s2 문자 비교, 만일 다르다면 
				return ("false"); // false 출력 
			}
			i++; // 다음 문자로 이동 
		}
		return ("true"); // 문자열 끝까지 왔다면 true 출력 
	} else { // s2가 더 길다면 
		while(s2[i] != '\0') { // s2 문자열 끝까지 반복 
			if (s1[i] != s2[i]) {
				return ("false");
			}
			i++;
		}
		return ("true");	
	}
}

void str_change(char *so) {
	int i = 0;
	char sd[100]; // 바뀐 문자열을 저장할 sd 
	while(so[i] != '\0') { // so 문자열 끝까지 반복 
		if (so[i] == ' ') { // 해당 위치의 문자가 공백이라면 
			sd[i] = '_'; // sd 문자열의 해당 위치에 밑줄 넣기 
		} else { // 공백이 아니라면 
			sd[i] = so[i]; // 걍 so와 같은 문자열 넣기 
		}
		//printf("so[%d] : %c\n", i, so[i]);
		i++; // 다음 문자로 이동 
	}
	sd[i] = '\0'; // 문자열 끝에 문자열 종료 문자 넣기 여기서 i는? 
	printf("string : %s", sd); // sd 출력하 
}

int main(int argc, char *argv[]) {
	
	//str1 받기 
	char str1[100];
	gets(str1);
	//str2 받기 
	char str2[100];
	gets(str2);

	printf("%s\n", str_compare(str1, str2));
	str_change(str1);
	
	return 0;
}
