#include <stdio.h>
#include "headerUndUtil/sha.h"
#include <stdint.h>

typedef uint32_t u32t ;

int main(int argc, char *argv[]){
      u32t HforDB[8];



      //to hash
      u32t * H = HashAfile(argv[1]);
      for (int i = 0 ; i < 8 ; i++){
            HforDB[i] = H[i];
            printf("%08x", HforDB[i]);
      }
      
      printf("\n");

      //write section
      FILE *binWRITE = fopen(argv[2], "wb");

      int n = 8;
      
      fwrite(HforDB, sizeof(u32t), n, binWRITE);

      free(H);


      return 0;
}

