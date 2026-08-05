#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include "headerUndUtil/sha.h"


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

int bjorn(char *path){

      DIR *dir;
      struct dirent *entry;
      dir = opendir(path);

      if (dir == NULL){
            printf("can't open");
            chdir("../");
            return -1 ;
      }

      chdir(path);
      while(entry = readdir(dir)){
            if (entry->d_type == DT_DIR){
                  if ((strcmp(entry->d_name, ".") == 0) 
                        || (strcmp(entry->d_name, "..") == 0)){
                        continue;
                  }
                  bjorn(entry->d_name);
            }

            else if(entry->d_type == DT_REG){

                  struct stat file; 
                  int Fp = open(entry->d_name, O_RDONLY);
                  fstat(Fp, &file);

                  if ((file.st_mode & S_IEXEC) 
                        || (file.st_mode & S_IXGRP)
                        || ( file.st_mode & S_IXOTH)){
                        LinearComparison(&file, &Fp);
                  }
                  close(Fp);
            }
      }

      chdir("../");

      if (closedir(dir) == -1){
            printf("Can't close");
            return -1 ;
      }
}

int main(){
      chdir("/home/draco/");
      bjorn("./");
      return 0 ;
}
