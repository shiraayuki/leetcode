#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

bool isReverseWord(const char *s, const char *t) {
  if (strlen(s) != strlen(t)) {
    return false;
  }
  t += strlen(t) - 1;
  while (*s != '\0') {
    if (*s != *t) {
      return false;
    }
    s++;
    t--;
  }
  return true;
}

int main() {
  const char *s = "anagram";
  const char *t = "nagaram";

  printf("%s\n", isReverseWord(s, t) ? "true" : "false");

  return 0;
}
