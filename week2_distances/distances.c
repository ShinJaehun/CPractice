#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} Point;

int main(int argc, char *argv[]) {
	
	Point A;
	scanf("%d %d", &A.x, &A.y);
	
	Point B;
	scanf("%d %d", &B.x, &B.y);
	
	Point C;
	scanf("%d %d", &C.x, &C.y);
	
	double AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	printf("AB의 거리는 : %lf", AB);

	double BC = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
	printf("BC의 거리는 : %lf", BC);	
	
	double CA = sqrt(pow((A.x - C.x), 2) + pow((A.y - C.y), 2));
	printf("CA의 거리는 : %lf", CA);
	
    double lengths[2];
  
    lengths[0] = AB;
    lengths[1] = BC;
    lengths[2] = CA;
    
	int i;
	double max;
	max = lengths[0];
	for (i = 1; i < 2; i++) {
		if (lengths[i] > max) {
			max = lengths[i];
		}
	}
	
	printf("최대값은 %lf", max);
	
    if (max == AB) {
    	if (AB < BC + CA) {
    		printf("true");
		} else {
			printf("false");
		}
	}
	if (max == BC) {
    	if (BC < AB + CA) {
    		printf("true");
		} else {
			printf("false");
		}
	}
	
	if (max == CA) {
    	if (CA < BC + AB) {
    		printf("true");
		} else {
			printf("false");
		}
	}

//	숫자 셋을 비교하기 실패
// 
//	if  (AB > BC) {
//		if (AB  > CA) {
//			if (AB > BC + CA) {
//				printf("true");
//			} else {
//				printf("false");
//			}
//		}else {
//			if (CA > BC + AB) {
//				printf("ture") ;
//			}else {
//				printf("false");
//			}
//		}
//	}
//	
//	if  (BC > AB) {
//		if (BC  > CA) {
//			if (BC > AB + CA) {
//				printf("true");
//			} else {
//				printf("false");
//			}
//		}else {
//			if (CA > BC + AB) {
//				printf("ture") ;
//				
//			}else {
//				printf("false");
//			}
//		}
//	}
//		
//	if  (CA > BC) {
//		if (CA  > AB) {
//			if (CA > BC + AB) {
//				printf("true");
//			} else {
//				printf("false");
//			}
//		}else {
//			if (AB > BC + CA) {
//				printf("ture") ;
//				
//			}else {
//				printf("false");
//			}
//		}
//	}
	
	return 0;
}

