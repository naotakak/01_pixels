#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
  int ppm, height, width;

  ppm = open("picmaker.ppm", O_CREAT | O_WRONLY, 0644);
  write(ppm, "P3\n", sizeof(char *));
  write(ppm, "500 500\n", sizeof(char *));
  write(ppm, "255\n", sizeof(char *));

  for (height = 0; height < 500; height ++) {
    for (width = 0; width < 500; width ++) {
      write(ppm, "100 100 100 ", sizeof(char *));
    }
    write(ppm, "\n", sizeof(char *));
  }
  close(ppm);
  return 0;
}
