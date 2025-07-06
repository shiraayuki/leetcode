#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) { return *(char *)a - *(char *)b; }

bool isAnagram(char *s, char *t) {
  size_t sizeS = strlen(s);
  size_t sizeT = strlen(t);

  if (sizeS != sizeT) {
    return false;
  }

  qsort(s, sizeS, sizeof(char), cmp);
  qsort(t, sizeT, sizeof(char), cmp);

  while (*s != '\0') {
    if (*s != *t) {
      return false;
    }

    s++;
    t++;
  }
  return true;
}

int main() {
  char *s = "anagram";
  char *t = "nagaram";

  return 0;
}
