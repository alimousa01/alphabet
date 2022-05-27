#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  int ret_code = 0;
  // we simply loop through the lower alphabet
  for (char c = 'a'; (ret_code != EOF) && (c <= 'z'); c++)
    ret_code = putc (c, stdout);
//hello WORLD

  /* in case for whatever reason we got an EOF */
  if (ret_code == EOF) {
    if (ferror (stdout)) {
      perror ("putc()");
      fprintf (stderr, "putc() failed in file %s at \
                        line # %d\n", __FILE__, __LINE__ - 7);
      exit (EXIT_FAILURE);
    }
  }
  putc ('\n', stdout);

  return EXIT_SUCCESS;
}
