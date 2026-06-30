#ifndef CHLARA_H
#define CHLARA_H
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

void append(char data, DDD *new);
void printAL2(DDD *new);
void DVolAppend(DesVolkes * arr, DDD *IO);

#endif 
