#include <stdio.h>
#include <stdlib.h>
#include "sha.c"

int main(){
      FILE *f= fopen("data.txt","rb");
      fseek(f, 0, SEEK_END);
      long len = ftell(f);
      rewind(f);

      unsigned char * buffer = malloc(len);
      fread(buffer,1,len,f);
      fclose(f);

      u32t * H = sha256(buffer);
      for (int p = 0; p < 8; p++){
            printf("%08x", H[p]);
      }
      printf("\n");
      free(H);
      
}
