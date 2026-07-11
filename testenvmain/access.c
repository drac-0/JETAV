#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>



int main(int argc, char *argv[]){

      struct stat file;
      stat(argv[1], &file);
      printf("%d\n", file.st_mode);

      if ((file.st_mode & S_IEXEC) 
            || (file.st_mode & S_IXGRP)
            || ( file.st_mode & S_IXOTH)){

            printf("executable\n");

            if ((file.st_mode & S_IFMT) == S_IFDIR){
                  printf("directory\n");
            }

            
      }

      /*
      int FD = open("./a.out", 'r');

      struct stat sb;
      struct stat *Psb = &sb;
      stat("/home/draco/vode/AV/testenvmain/a.out", &sb);
      fstat(FD, Psb);
      printf("%d\n", sb.st_mode & 0777);
      printf("%d\n", Psb->st_mode & 0777);
      */

}
