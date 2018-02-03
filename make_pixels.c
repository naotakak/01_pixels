#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
  int ppm, height, width;
  int r = 100;
  int g = 100;
  int b = 100;
  char line[20];

  ppm = open("picmaker.ppm", O_CREAT | O_WRONLY, 0644);

  write(ppm, "P3\n", sizeof("P3\n"));
  write(ppm, "500 500\n", sizeof("500 500\n"));
  write(ppm, "255", sizeof("255"));
  //strcat(line, "P3\n500 500\n255\n");
  for (height = 0; height < 500; height ++) {
    write(ppm, "\n", sizeof("\n"));
    //strcat(line, "\n");
    for (width = 0; width < 500; width ++) {
      r = width % 256;
      g = height % 256;
      b = width % 256;
      sprintf(line, "%d %d %d", r, g, b);
      write(ppm, line, sizeof(line));
    }
  }
  //write(ppm, line, sizeof(line));
  close(ppm);
  return 0;
}
