#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<errno.h>
#define MAGIC_LEN 4
#define TIME_STAMP_LEN 4
#define BUF_LEN 4048
unsigned char buf[BUF_LEN];
#define u8 unsigned char 
int main()
{
  int fd;
  char magic[4];
  char timestamp[4];
  int size;
  
  if((fd = open("test.pyc",O_RDONLY)) < 0) {
    perror("open");
    exit(errno);
  }
  
  if(read(fd,magic,MAGIC_LEN) < 0) {
    perror("magic");
    exit(errno);
  }

  if(read(fd,timestamp,TIME_STAMP_LEN) < 0) {
    perror("timestamp");
    exit(errno);
  }
  
  printf("************magic***************\n");
  printf("%02x%02x%02x%02x\n",(u8) magic[0],(u8)magic[1]
	 ,(u8) magic[2],(u8)magic[3]);
  

  printf("***********timestamp************\n");
  printf("%02x%02x%02x%02x\n",(u8) timestamp[0],(u8) timestamp[1] 
	 ,(u8) timestamp[2],(u8) timestamp[3]);
  
  printf("**********marshelcode***********\n");
  while((size = read(fd,buf,BUF_LEN)) > 0) {
    decode(buf,size);
  }
}
