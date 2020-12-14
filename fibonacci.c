#include <stdio.h>

int fibonacci(int n) {
  if (n == 1 || n ==2) return 1;
  else {
    printf("[n=%d]\n", n);
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main()
{
	printf("result : %d\n", fibonacci(5));
	return 0;
}
