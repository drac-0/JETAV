#include <sys/types.h>
#include "Chlara_oldersister.h"
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

DDD * Womb(DDD *I1, DDD *I2){
      DDD *ConI1I2 = malloc(sizeof(DDD));
      ConI1I2->Pdata = 0 ; 
      ConI1I2->len = ConI1I2->keepUp = 0;
      int count = 0 ;
      while (I1->Pdata[count]){
            append(I1->Pdata[count++], ConI1I2);
      }

      count = 0 ;

      while (I2->Pdata[count]){
            append(I2->Pdata[count++], ConI1I2);
      }

      return ConI1I2;
}
