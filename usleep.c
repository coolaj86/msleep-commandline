#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int
strrcmp(const char* a, const char* b)
{
  int i;
  char diff;
  int a_len = strlen(a);
  int b_len = strlen(b);
  int min_len = (a_len < b_len) ? a_len : b_len;

  // place pointer just before the trailing \0
  a += a_len - 1;
  b += b_len - 1;

  for (i = 0; i < min_len; i += 1)
  {
    diff = *a - *b;
    if (diff != 0) { return diff; }
    a -= 1;
    b -= 1;
  }

  return 0;
}

void
usage(char* command)
{
  printf("Usage: %s <integer>\n", command);
}

int
main(int argc, char* argv[])
{
  useconds_t usecs;
  char* command = argv[0];
  char* cusecs = argv[1];

  if (1 == argc) { usage(command); return 1; }

  usecs = atoi(cusecs);

  if (0 == usecs) { usage(command); return 1; }

  if (0 == strrcmp(command, "msleep"))
  {
    usecs *= 1000;
  }

  usleep(usecs);

  return 0;
}
