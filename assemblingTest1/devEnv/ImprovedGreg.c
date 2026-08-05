#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef uint64_t u64t;

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
            size_t Loop = len / 64;
            size_t Re = len % 64; 
            for (int i = 0 ; i < Loop; i++){
                  /*
                   *    multichained padding 
                  */ 
                  unsigned char * gBIT = calloc(512, 1); 
                  for (int i = 0 ; i < 64; i++){
                        gBIT[] = ;
                  }
            }
      }

      else{
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
      }
}

int main(int argc, char *argv[]){
      struct stat file;
      stat(argv[1], &file);
      printf("%d\n", file.st_size);
      Gregtest("aaa", file.st_size);

}
