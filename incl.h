#ifndef INCL_H
#define INCL_H

// This is a custom header I am working onto

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// It is a custom integer to string function ( but the main part of this is later )
void IntToString(int n,char data[], int len)
{
  FILE *fp;
  fp = fopen("temp.t","w");
  fprintf(fp,"%d",n);
  fclose(fp);

  FILE *r;
  r = fopen("temp.t","r");
  fgets(data,len+1,r);
  fclose(r);

  remove("temp.t");
}

int power(int base, int expon)
{
  int t=base;
  for(int i = 1; i < expon; i++)
    t *= base;

  return t;
}

// FILE I/O ( Here starts my custom FILE I/O )
typedef struct syscallfilesys
{
  int filed;
  char buffer[];
}FILE_STREAM;


// syscalls
int stream_open(const char* name,int m){
  // using open syscall
  return open(name,m);
}

void stream_read(int filed,char buffer[],size_t size)
{
  // using read syscall
  
    lseek(filed,0,SEEK_SET);
    read(filed,buffer,size);
  
}

void stream_write(int filed,char msg[],size_t msgsize)
{

    write(filed,msg,msgsize);

}

void stream_end(int filed)
{
    close(filed);

}

#endif //INCL_H
