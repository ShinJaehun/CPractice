#include <stdio.h>

int compare(int n, char * words) {
  if (n == 1) return 1;
  else {
    printf("%s\n", words);
    printf("word[0] : %c\n", words[0]);
    printf("word[n-2] : %c\n", words[n-2]);
    if (words[0] == words[n-2]){
      char newwords[n-2];
      int i = 0;
      while (i == n-3) {
        newwords[i] = words[i+1];
    	printf("newwords[%d] : %c // word[%d+1] %c\n", i, newwords[i], i, words[i+1]);
	i++;
      }
      newwords[n-2] = '\0';
      printf("newwords : %s\n", newwords);

      compare(n-1, newwords);
    }
  }
}

int main()
{
	char words[] = "noon";
	printf("sizeof words : %ld\n", sizeof(words));

	compare(sizeof(words), words);
	return 0;
}
