#include <stdio.h>
#include <stdlib.h>

double average(int n, int vs[]);
double dispersion(int n, int vs[], double a);
int maximum(int n, int vs[]);
int minimum(int n, int vs[]);

int main(int argc, char *argv[]) {
	
	int num;
	scanf("%d", &num);
	
	int values[num];

	int i;
	for (i = 0; i < num; i++) {
		scanf("%d", &values[i]);
	}
	
// 출력하기	
//	for (i = 0; i < SIZE; i++) {
//		printf("%d\n", values[i]);
//	}

	double avg = average(num, values);
	printf("average is %.4f\n", avg);
	
	double dis = dispersion(num, values, avg);
	printf("dispersion is %.4f\n", dis);
	
	int max = maximum(num, values);
	printf("maximum is %d\n", max);
	
	int min = minimum(num, values);
	printf("minimum is : %d\n", min);

	return 0;
}

double average(int n, int vs[]) {
	int sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		sum = sum + vs[i];
	}
	return sum/n;
}

double dispersion(int n, int vs[], double a) {
	double disper = 0;
	int i;
	for (i = 0; i < n; i++) {
		disper += (vs[i] - a) * (vs[i] - a);
	}
	
	return disper/n;	
} 

int maximum(int n, int vs[]) {
	int m = vs[0];
	int i;
	for (i = 1; i < n; i++) {
		if (vs[i] > m) {
			m = vs[i];
		}
	}
	return m;
}

int minimum(int n, int vs[]) {
	int m = vs[0];
	int i;
	for (i = 1; i < n; i++) {
		if (vs[i] < m) {
			m = vs[i];
		}
	}
	return m;
}
