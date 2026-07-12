#include <stdio.h>
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
                  printf("folder name: %s\n", entry->d_name);
                  bjorn(entry->d_name);
            }
            else if(entry->d_type == DT_REG){
                  printf("file name: %s\n", entry->d_name);
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
