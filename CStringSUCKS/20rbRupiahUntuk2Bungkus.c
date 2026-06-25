#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct{
      char *Pdata;
      size_t keepUp;
      size_t len;
}DDD;

typedef struct{
      DDD ** string;
      size_t keeUp2;
      size_t len;

}DesVolkes;

void append(char data, DDD *new ){
      if (new->keepUp >= new->len){
            if (new->len == 0 ) new->len = 256;
            else {new->len *= 2;}
            new->Pdata = realloc(new->Pdata, new->len * sizeof(*new->Pdata)); // culprit
      }
      new->Pdata[new->keepUp++] = data;
      new->Pdata[new->keepUp] = '\0';
}

/*
void printAL(DDD *new,int len){
      for (int i = 0 ; i < len; i++){
            if (new->Pdata[i] == '\0') break;
            printf("%c", new->Pdata[i]);
      }
      printf("\n");
}
*/

//fits the C idiomacy
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

int main(){
      DDD dinar1 = {0,0,0} ;
      append('a', &dinar1);
      append('a', &dinar1);
      append('a', &dinar1);

      DDD dinar2 = {0,0,0} ;
      append('b', &dinar2);
      append('b', &dinar2);
      append('b', &dinar2);

      DDD dinar3 = {0,0,0} ;
      append('c', &dinar3);
      append('c', &dinar3);
      append('c', &dinar3);

      DesVolkes test ;

      DVolAppend(&test, &dinar1);
      DVolAppend(&test, &dinar2);
      DVolAppend(&test, &dinar3);
      printAL2(test.string[0]);
      printAL2(test.string[1]);
      printAL2(test.string[2]);
      //printAL((test.string[0]), (test.string[0]->keepUp));
      //printAL((test.string[1]), (test.string[1]->keepUp));
}
