#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct stat stt ;


int main(int argv, char *argc[]){
      size_t count = 1;
      while (argc[count]){
            stt sb;
            stat(argc[count], &sb);

            

            count++;
      }

}


