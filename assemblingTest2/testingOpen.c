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

/*
void LinearComparison(struct stat *file, int *Fp){
      //since when i write a function name that's self explanatory?. MEH 
      ssize_t n ;
      unsigned char buf[BUFSIZ];

      unsigned char *new = malloc(file->st_size);
      int i = 0 ;
      while ((n = read(*Fp, buf, BUFSIZ)) > 0){
            memcpy(new + i, buf, n);
            i += n;
      }

      u32t *H = sha256(new, file->st_size);
      for (int i = 0; i < 8; i++) {
            printf("%08x", H[i]);
      }
      printf("\n");
      free(new);
      free(H);
}
*/
void main(){
      struct stat file;
      ssize_t n ;
      unsigned char buf[BUFSIZ];

      int Pp = open("./fil.txt", O_RDONLY);
      fstat(Pp, &file);

      n = read(Pp, buf,64);

      if (file.st_size <= 54){
            printf("NORMAL\n");
            u32t * H = sha256(buf, n, file.st_size);
            for (int i = 0 ; i < 8 ; i++){
                  printf("%08x",H[i]);
            }
            printf("\n");

      }

      else if (file.st_size > 54 && file.st_size < 64){
            printf("A MEDIUM FILE\n");
      }

      else {
            printf("A BIG FILE\n");
            size_t Re = file.st_size % 64; 
            printf("%d\n", Re);
            u32t * H = sha256(buf, n, file.st_size);

            while (n > 0){
                  H = MultiSha(buf, H, n, file.st_size);
                  n = read(Pp, buf,64);
            }

            for (int i = 0 ; i < 8 ; i++){
                  printf("%08x",H[i]);
            }

            printf("\n");
      }


}
