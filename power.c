#include <stdio.h>

int power(int x, int n) {
  if (n == 0) {
    return 1;
  } else {
    printf("[x=%d, n=%d]\n", x, n);
    return power(x, n-1) * x;
  }
}

int main()
{
	printf("result : %d\n", power(2, 3));
	return 0;
}
