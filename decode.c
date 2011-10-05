#include<stdio.h>
#include<opcode.h>
void decode(char *buf,int size)
{
  int i = 0;
  int next_index;
  char *bc_instruction1;
  char num;
  while(i < size) {
    
    next_index = read_byte(buf[i]); 
    num = buf[i];
   
    bc_instruction1 = ((unsigned char )num < 0x8F) ?
      op_buf[num].bc_instruction:"INVALID";
   
    
    printf("\t%d:%s",i,bc_instruction1);
    
    if(next_index) {
      printf(":\t%d\n",*((unsigned short int *) &buf[i+1]));
    } else {
      printf("\n");
    }
    
    i += (next_index+1);
  }
}
  
