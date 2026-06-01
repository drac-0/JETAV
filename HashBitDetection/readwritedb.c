#include <stdio.h>
#include "sha.c"
#include <stdint.h>

typedef uint32_t u32t ;

int main(int argc, char *argv[]){
      u32t HforDB[8];


      //read section
      FILE *binREAD = fopen(argv[1], "rb"); //so argv[0] is my compiled program file?, huh?

      fseek(binREAD, 0, SEEK_END); //move cursor to the end 
      long len = ftell(binREAD); //count the len of a file binary contect
      rewind(binREAD); //what the fuck?

      unsigned char * buffer = malloc(len); //where i will write the buffer
      fread(buffer,1,len,binREAD); //read from f, 1-len, put it to buffer

      //to hash
      u32t * H = sha256(buffer);
      for (int i = 0 ; i < 8 ; i++){
            HforDB[i] = H[i];
            printf("%08x", HforDB[i]);
      }
      
      printf("\n");

      //write section
      FILE *binWRITE = fopen(argv[2], "wb");

      int n = 8;

      fwrite(HforDB, sizeof(u32t), n, binWRITE);

      fclose(binWRITE);
      fclose(binREAD);
      free(H);


      return 0;
}

