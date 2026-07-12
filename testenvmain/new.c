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

      //debugging purpose
      printf("current path: %s\n", path);
      char cwd[PATH_MAX];
      if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Current working dir: %s\n", cwd);
      }

      else {
            perror("getcwd() error");
            return ;
      }
      while(entry = readdir(dir)){
            if (entry->d_type == DT_DIR){
                  if ((strcmp(entry->d_name, ".") == 0) 
                        || (strcmp(entry->d_name, "..") == 0)){
                        continue;
                  }
                  printf("recursion\n");
                  bjorn(entry->d_name);
            }
            else if(entry->d_type == DT_REG){
                  printf("file name: %s", entry->d_name);
            }
            printf("\n");
      }

      chdir("../");


      if (closedir(dir) == -1){
            printf("Can't close");
            return ;
      }
}

int main(){
      chdir("/home/draco/");



      /*
      DIR *dir ;
      struct dirent *entry;

      dir = opendir("2pac/");

      if (dir == NULL){
            printf("Unable to open");
            return 1;
      }

      while (entry = readdir(dir)){
            if (entry->d_type == DT_DIR){
                  //filter
                  if ((strcmp(entry->d_name, ".") == 0) 
                        || (strcmp(entry->d_name, "..") == 0)){
                        continue;
                  }
                  printf("folder name: %s", entry->d_name);
            }

            else if(entry->d_type == DT_REG){
                  printf("file name: %s", entry->d_name);
            }
            printf("\n");
      }

      if (closedir(dir) == -1){
            printf("Can't close");
            return 1;
      }

      printf("\n");
      printf("\n");
      printf("FUNC CALL SEPARATOR\n");
      printf("\n");
      printf("\n");
      */

      bjorn("./");

      return 0 ;
}
