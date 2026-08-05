#include "headerUndUtil/sha.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef uint64_t u64t;

typedef uint32_t u32t;
//some cunt should be death already
//some cunt serve no clear purpose in this world
//i should kill myself already
//i serve no real purpose in this world

//i don't want to be anywhere
//i don't want to be anybody
//i don't want to be with anyone

//it's may or may not be fine
//i am not smart enough to figure it out

//this condition surely tormenting
//but what can i do
//i am just a selfish piece of shit anyway
 
unsigned char * Gregtest(unsigned char * Sinput, u64t len){
      if(len == 64){
            unsigned char * gBIT = calloc(512, 1); 
            for (int i = 0 ; i < 64; i++){
                  gBIT[i] = Sinput[i];
            }
            return gBIT;
      }

      unsigned char * gBIT= calloc(512, 1); 
      gBIT[len] = 0x80 ;

      for (int i = 0; i < len; i++){
            gBIT[i] = Sinput[i];
      }

      u64t bitLen = len * 8;
      gBIT[56] = (bitLen >> 56) & 0xFF;
      gBIT[57] = (bitLen >> 48) & 0xFF;
      gBIT[58] = (bitLen >> 40) & 0xFF;
      gBIT[59] = (bitLen >> 32) & 0xFF;
      gBIT[60] = (bitLen >> 24) & 0xFF;
      gBIT[61] = (bitLen >> 16) & 0xFF;
      gBIT[62] = (bitLen >> 8)  & 0xFF;
      gBIT[63] = (bitLen)       & 0xFF; 
      return gBIT;
      
}

int main(int argc, char *argv[]){
      struct stat file;
      ssize_t n ;
      unsigned char buf[BUFSIZ];

      int Pp = open("./fil.txt", O_RDONLY);
      fstat(Pp, &file);

      n = read(Pp, buf,BUFSIZ);

      //base of the multi chunking
      //
      while (n > 0){
            buf[n] = '\0';
            printf("%d ", n);
            printf("%s\n", buf);
            u32t * H = MultiSha(buf, H, n);

            for (int i = 0 ; i < 8 ; i++){
                  printf("%08x",H[i]);
            }
            
            printf("\n");
            n = read(Pp, buf,BUFSIZ);
      }
}
