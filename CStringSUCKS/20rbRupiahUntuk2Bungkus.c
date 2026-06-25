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
      new->Pdata[new->keepUp++] = '\0';
}

void printAL(DDD *new,int len){
      for (int i = 0 ; i < len; i++){
            if (new->Pdata[i] == '0') break;
            printf("%c", new->Pdata[i]);
      }
      printf("\n");
}

void DVolAppend(DesVolkes * arr, DDD IO){
      if (arr->len >= arr->keeUp2){
            if (arr->len == 0 ) arr->len = 256;
            else {arr->len *= 2;}
            arr->string = realloc(arr->string, arr->len * sizeof(*arr->string));
      }
      arr->string[arr->keeUp2++] = &IO;
}

int main(){
      DDD testDinar = {0,0,0} ;
      append('a', &testDinar);
      append('a', &testDinar);
      append('a', &testDinar);

      DDD dinar2 = {0,0,0} ;
      append('b', &dinar2);
      append('b', &dinar2);
      append('b', &dinar2);

      DesVolkes test ;

      DVolAppend(&test, testDinar);
      DVolAppend(&test, dinar2);
      printAL((test.string[0]), (test.string[0]->len));
      printAL((test.string[1]), (test.string[1]->len));
}
