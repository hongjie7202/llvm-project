// RUN: %clangxx -O0 -g %s -o %t && %run %t

#include <grp.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  const char *nobody;

  if (!(nobody = group_from_gid(0, 0)))
    exit(1);

  if (strlen(nobody))
    exit(0);

  return 0;
}
