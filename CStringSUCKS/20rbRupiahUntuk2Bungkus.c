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

typedef struct{
      DDD *string;
      size_t keeUp2;
      size_t len;

}DesVolkes;

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

void DVolAppend(DesVolkes * arr, DDD *I0){
      if (arr->len >= arr->keeUp2){
            if (arr->len == 0 ) arr->len = 256;
            else {arr->len *= 2;}
            arr->string = realloc(arr->string, arr->len * sizeof(*arr->string));
      }
}

int main(){
      DDD testDinar = {"faiz",0,0} ;
      printAL(&testDinar, sizeof(testDinar.Pdata) 
              / sizeof(testDinar.Pdata[0]));
      DesVolkes test ;
      DVolAppend(&test, &testDinar);
      

}

