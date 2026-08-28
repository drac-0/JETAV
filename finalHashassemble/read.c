#include <stdio.h>
#include <stdlib.h>
#include "headerUndUtil/sha.h"


void main(int argv, char * argc[]){
      FILE *binREAD= fopen(argc[1], "rb");
      fseek(binREAD, 0, SEEK_END); //move cursor to the end 
      long len = ftell(binREAD); //count the len of a file binary contect
      rewind(binREAD); //what the fuck?

      u32t * buffer = malloc(len); //where i will write the buffer
      fread(buffer,1,len,binREAD); //read from f, 1-len, put it to buffer

      for (int i = 0 ; i < 8 ; i++){
            printf("%08x", buffer[i]);
      }
      printf("\n");
}
