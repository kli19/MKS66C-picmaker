#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

int main(){
  time_t currentTime = time(NULL);
  srand(currentTime);
  int color = 0;
  int fd, i, j;
  char line[20];
  int rgb[3];
  fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  snprintf(line, sizeof(line), "P3 500 500 255\n");
  write(fd, line, strlen(line));
  for(i=0; i<500; i++){
    for(j=0; j<500; j++){
      if (rand()%300 == 0){
	color = 255;
      }
      else{
	color = 0;
      }      
      rgb[0]= color;
      rgb[1]= color;
      rgb[2]= color;
      snprintf(line, sizeof(line), "%d %d %d ", rgb[0], rgb[1], rgb[2]);
      write(fd, line, strlen(line));
    }
  }
}
