#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>


void bjorn(char *path){

      DIR *dir;
      struct dirent *entry;
      dir = opendir(path);

      if (dir == NULL){
            printf("can't open");
            chdir("../");
            return ;
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
                  stat(entry->d_name, &file);

                  if ((file.st_mode & S_IEXEC) 
                        || (file.st_mode & S_IXGRP)
                        || ( file.st_mode & S_IXOTH)){

                        printf("%s are executable\n", entry->d_name);
                  }
            }
      }

      chdir("../");

      if (closedir(dir) == -1){
            printf("Can't close");
            return ;
      }
}

int main(){
      chdir("/home/draco/");
      bjorn("./");
      return 0 ;
}
