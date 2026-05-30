#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "sha.c"

typedef uint32_t u32t ;
int main(){
      FILE *binREAD= fopen("./db/kl256", "rb");
      fseek(binREAD, 0, SEEK_END); //move cursor to the end 
      long len = ftell(binREAD); //count the len of a file binary contect
      rewind(binREAD); //what the fuck?

      u32t * buffer = malloc(len); //where i will write the buffer
      fread(buffer,1,len,binREAD); //read from f, 1-len, put it to buffer

      for (int i = 0 ; i < 8 ; i++){
            printf("%08x", buffer[i]);
      }
      

}


