#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(int n, char * words) {
  printf("n = %d\n", n);
  if (n == 2) {
    if (words[0] == words[1]) return 1;
    else return 0;
  } else if (n == 1) {
    return 1;
  } else {
    printf("%s\n", words);
    printf("word[0] : %c\n", words[0]);
    printf("word[n-1] : %c\n", words[n-1]);
    if (words[0] == words[n-1]){
      char newwords[n-1];
      int i = 0;
      while (i < n-2) {
        newwords[i] = words[i+1];
        printf("newwords[%d] : %c // word[%d+1] %c\n", i, newwords[i], i, words[i+1]);
        i++;
      }
      newwords[n-2] = '\0';
      printf("newwords : %s\n", newwords);

      compare(n-2, newwords);
    } else {
      return 0;
    }
  }
}

int main(int argc, char *argv[]) {
        char words[32];
        scanf("%s", words);

        printf("strlen of words : %ld\n", strlen(words));
        if (compare(strlen(words), words)) printf("true\n");
        else printf("false\n");
        return 0;
}
