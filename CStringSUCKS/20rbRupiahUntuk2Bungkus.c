#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

typedef struct{
      char *Pdata;
      size_t keepUp;
      size_t len;
}DDD;

void append(int data, DDD *new ){
      if (new->len >= new->keepUp){
            if (new->len == 0 ) new->len = 256;
            else {new->len *= 2;}
            new->Pdata = realloc(new->Pdata,new->len * sizeof(*new->Pdata));
      }
      new->Pdata[new->keepUp++] = data;
      new->Pdata[new->keepUp++] = '\0';
}
void printAL(DDD *new,int len){
      for (int i = 0 ; i < len; i++){

            printf("%c", new->Pdata[i]);
      }
}

int main(){
      DDD testDinar = {0} ;
      append('a', &testDinar);
      printf("%c", testDinar.Pdata[0]);
      append('a', &testDinar);
      append('a', &testDinar);
      append('a', &testDinar);
      append('a', &testDinar);
      append('a', &testDinar);
      printAL(&testDinar, sizeof(testDinar.Pdata)/ sizeof(testDinar.Pdata[0]));
}
