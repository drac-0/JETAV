#include "headerUndUtil/sha.h"
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
typedef uint32_t u32t ;

void main(){
      struct stat file;
      ssize_t n ;
      unsigned char buf[BUFSIZ];

      int Pp = open("./fil.txt", O_RDONLY);
      fstat(Pp, &file);

      n = read(Pp, buf,64);

      //base of the multi chunking
      while (n > 0){
            buf[n] = '\0';
            printf("%d ", n);
            printf("%s\n", buf);
            n = read(Pp, buf,64);
      }

}
