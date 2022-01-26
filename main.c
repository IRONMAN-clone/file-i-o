#include <stdio.h>
#include "incl.h"
#include <fcntl.h>

int main(int argc, char** argv)
{
  char msg[1500];
  char mymsg[50] = "Hello, World by CUSTOM I/O";
  
  FILE_STREAM fs;
  fs.filed = stream_open("random.txt",O_RDWR);
  stream_write(fs.filed,mymsg,sizeof(mymsg));
  
  size_t sz = sizeof(msg);
  stream_read(fs.filed,fs.buffer,sz);
  printf("%s\n",fs.buffer);

  
  return 0;
}








