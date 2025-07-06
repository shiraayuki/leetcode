#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) { return *(char *)a - *(char *)b; }

bool isAnagram(char *s, char *t) {
  // Because i use the size of the 'strings' later again, its smarter
  // to store them to minmize the callbacks.
  size_t sizeS = strlen(s);
  size_t sizeT = strlen(t);

  // If the sizes are different there is no way to create an anagram,
  // so we can already exit here.
  if (sizeS != sizeT) {
    return false;
  }

  // If we sort both arrays, we can simply iterate over one of them once
  // and compare each loaction with the other array. In case they differ
  // we know it cant be an anagram so we return false.
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
