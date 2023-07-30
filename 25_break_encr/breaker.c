#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double find_largest_freq(int* cnt) {
  int max = cnt[0];
  int idx = 0;
  for(int i = 1; i < 26; ++i) {
    if(cnt[i] > max) {
      max = cnt[i];
      idx = i;
    }
  }
  return idx;
}

int breaker(FILE* f, int *cnt) {
  int c;
  while((c = fgetc(f)) != EOF) {
      if(isalpha(c)) {
	cnt[c - 'a']++;
      }
    }
    int idx = find_largest_freq(cnt);
    return (idx + 26 - ('e' - 'a')) % 26;
}

int main(int argc, char **argv) {
      if (argc != 2) {
        fprintf(stderr, "Usage: breaker inputFileName\n");
        return EXIT_FAILURE;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }
    int alphalist[26] = {0};
    int key = breaker(fp, alphalist);
    printf("%d\n", key);
    if (fclose(fp) != 0) {
      perror("Failed to close the input file!");
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  
}

