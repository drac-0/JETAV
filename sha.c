#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t u64t ;

void bitV(char a){ 
      unsigned char bit[10] ;
      int i = 0 ;
      while (a != 0){
            if (a & 1 == 1){
                  bit[i++] = '1';
            }
            else{
                  bit[i++] = '0';
            }
            a /= 2;
      }
      while (i < 8){
            bit[i++] = '0';
      }
      bit[i] = '\0';
      
      for (int j = 0; j < i/2; j++ ){
            int temp = bit[j];
            bit[j] = bit[i - j - 1];
            bit[i - j -1 ] = temp;
      }
      printf("%s\t", bit);
}

void *Greg_bitLOC(char * Sinput, int len){
      unsigned char * gBIT= calloc(512, 1);
      int i = 0; 
      //allocation for the input bit
      for (; i < len; i++){
            gBIT[i] = Sinput[i];
            bitV(gBIT[i]);
      }
      printf("\n");
      gBIT[len] = 0x80 ;//(128 in decimal with bin representation of 10000000);
      
      uint64_t bitLen = (uint64_t)len * 8;
      //process of merge bitlen into the main padding
      gBIT[56] = (bitLen >> 56) & 0xFF;
      gBIT[57] = (bitLen >> 48) & 0xFF;
      gBIT[58] = (bitLen >> 40) & 0xFF;
      gBIT[59] = (bitLen >> 32) & 0xFF;
      gBIT[60] = (bitLen >> 24) & 0xFF;
      gBIT[61] = (bitLen >> 16) & 0xFF;
      gBIT[62] = (bitLen >> 8)  & 0xFF;
      gBIT[63] = (bitLen)       & 0xFF; 
      
      //i will get rid of this visualization later
      for (int j = 0 ; j < 64; j++ ){
            if (j % 4 == 0 ){
                  printf("\n\n");
            }
            bitV(gBIT[j]);
      }
      printf("\n");
      return gBIT;
}


int main(){
      unsigned char word[10] = "abcdefghij";
      Greg_bitLOC(word, strlen(word));
}
