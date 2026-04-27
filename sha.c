#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uchar.h>
#include <math.h>

typedef uint64_t u64t;
typedef uint32_t u32t;

//here is all the function.
//wait which one is small sigma again?
//fuck
u32t ROTR(unsigned char num, int val){
      return  ((num >> val) | (num << (8-val)));
}

u32t gSSIGMA1(unsigned char gBIT){
      return ROTR(gBIT, 7) ^ ROTR(gBIT, 18) ^ gBIT >> 3;
}

u32t gSSIGMA2(unsigned char gBIT){
      return ROTR(gBIT, 17) ^ ROTR(gBIT, 19) ^ gBIT >> 10;
}

u32t gSIGMA1(unsigned char gBIT){
      return ROTR(gBIT, 2) ^ ROTR(gBIT, 13) ^ ROTR(gBIT, 22);
}

u32t gSIGMA2(unsigned char gBIT){
      return ROTR(gBIT, 6) ^ ROTR(gBIT, 11) ^ ROTR(gBIT, 25);
}


void binV(char a){ 
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

//padding function
void *Greg_bitLOC(char * Sinput, int len){
      unsigned char * gBIT= calloc(512, 1);
      int i = 0; 
      //allocation for the input bit
      for (; i < len; i++){
            gBIT[i] = Sinput[i];
      }
      printf("\n");
      gBIT[len] = 0x80 ;//(128 in decimal with bin representation of 10000000);
      
      u64t bitLen = (u64t)len * 8;
      //process of merge bitlen into the main padding
      //i will stick my note with this later
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
                  printf("\n");
            }
            binV(gBIT[j]);
      }
      printf("\n");
      return gBIT;
}

//instead of calculating the initial value, how i use a constant variable instead?
//well
//i guess that's my homework later.


// as my promise, i will just hard coded the hash initial value, 
// instead of calculating and allocating it by each call
// hence, this part would be multi-lined comment
/*
u32t *hashVal1(){
      u32t * prime8 = malloc(8 * sizeof(u32t));
      u32t primes[8] = {2,3,5,7,11,13,17,19};

      for (int i = 0 ; i < 8 ; i++){
            double bb ;
            double frac = modf(sqrt((double)primes[i]), &bb);
            u32t hashinitval= (u32t) (frac * 0x100000000ULL);
            prime8[i] = hashinitval;
            if (i % 4 == 0){
                  printf("\n");
            }
            printf("0x%08x, ",prime8[i] );
      }
      printf("\n");

      return prime8;
}


u32t *hasval2(){
      u32t *prime64 = malloc(65 * sizeof(u32t));
      u32t primes[64] = {
            2, 3, 5, 7, 
            11, 13, 17, 19,
            23, 29, 31, 37,
            41, 43, 47, 53,
            59, 61, 67, 71,
            73, 79, 83, 89,
            97, 101, 103, 107,
            109, 113, 127, 131,
            137, 139, 149, 151,
            157, 163, 167, 173,
            179, 181, 191, 193,
            197, 199, 211, 223,
            227, 229, 233, 239,
            241, 251, 257, 263,
            269, 271, 277, 281,
            283, 293, 307, 311
      };

      //other constant
      for (int j = 0 ; j < 64; j++){
            double newbb;
            double frac = modf(cbrt((double)primes[j]), &newbb);
            u32t other_Hashinitval = (u32t) (frac * 0x100000000ULL);
            prime64[j] = other_Hashinitval;
            if (j % 4 == 0 ){
                  printf("\n");
            }
            printf("0x%08x, ", prime64[j] );
      }
      printf("\n");
      return prime64;
}
*/

int main(){
      u32t H[8] = {
            0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 
            0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 

      };

      u32t h[64] = {
            0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 
            0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 
            0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 
            0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 
            0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 
            0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 
            0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 
            0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
            0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 
            0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 
            0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 
            0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 
            0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 
            0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
            0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 
            0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
      };

      // what to do next is to compute 64 word. 
      // with W function that defined as :
      // W(t) = 

      unsigned char word[10] = "abcd";
      unsigned char * gBITmain = Greg_bitLOC(word, strlen(word));
      free(gBITmain);
}
