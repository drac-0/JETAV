#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include "headerUndUtil/sha.h"
#include <errno.h>

int bjorn(char *path){
      printf("%s\n", path);

      DIR *dir;
      struct dirent *entry;
      printf("trying to open: %s from cwd: %s\n", path, getcwd(NULL, 0));
      dir = opendir(path);

      if (dir == NULL){
            printf("can't open\n");
            perror("opendir error");
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
                  int Pf = open(entry->d_name, O_RDONLY);
                  fstat(Pf, &file);

                  if ((file.st_mode & S_IEXEC) 
                        || (file.st_mode & S_IXGRP)
                        || ( file.st_mode & S_IXOTH)){
                        // Where hash and compare will be placed
                  }
                  close(Pf);
            }
      }

      chdir("../");

      if (closedir(dir) == -1){
            printf("Can't close\n");
            return -1 ;
      }
}

int main(){
      chdir("/home/draco/");
      bjorn("./");
      return 0 ;
}
