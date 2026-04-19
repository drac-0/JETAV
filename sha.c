#include <stdio.h>
#include <stdlib.h>

void bitV(char a){ 
      char bit[10] ;
      int i = 0 ;
      while (a != 0){
            if (a & 1 == 1){
                  bit[i++] = '1';
            }
            else{
                  bit[i++] = '0';
            }
            a /= 2;
            bit[i] = '\0';
      }
      
      for (int j = 0; j < i/2; j++ ){
            int temp = bit[j];
            bit[j] = bit[i - j - 1];
            bit[i - j -1 ] = temp;
      }
      printf("%s\t", bit);
}

void *Greg_bitLOC(char * Sinput, int len){
      int Greg_workingIndex = 0;

      //we can get rid of this visualitation later i guess
      for (int i = 0 ; i < len; i++){
            bitV(Sinput[i]);
      }


      printf("\n");
      char * gBIT= calloc(512, 1);
      char * dupG = gBIT;
      for (int i = 0 ; i < len * sizeof(char); i++){
      }

}


int main(){
      char word[10] = "abcdefghij";
      Greg_bitLOC(word, sizeof(word)/sizeof(word[0]));
}
