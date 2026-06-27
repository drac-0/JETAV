#include <sys/types.h>
#include "Chlara.h"
#include <stdlib.h>
#include <stdio.h>

void append(char data, DDD *new ){
      if (new->keepUp >= new->len){
            if (new->len == 0 ) new->len = 256;
            else {new->len *= 2;}
            new->Pdata = realloc(new->Pdata, new->len * sizeof(*new->Pdata)); // culprit
      }
      new->Pdata[new->keepUp++] = data;
      new->Pdata[new->keepUp] = '\0';
}


void printAL2(DDD *new){
      int i = 0 ;
      while (new->Pdata[i]){
            printf("%c", new->Pdata[i++]);
      }
      printf("\n");
}

void DVolAppend(DesVolkes * arr, DDD *IO){
      if (arr->len >= arr->keeUp2){
            if (arr->len == 0 ) arr->len = 256;
            else {arr->len *= 2;}
            arr->string = realloc(arr->string, arr->len * sizeof(*arr->string));
      }
      arr->string[arr->keeUp2++] = IO;
}


