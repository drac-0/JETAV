#include <stdio.h>
#include <dirent.h>
#include <string.h>

void bjorn(){

}

int main(){
      DIR *dir ;
      struct dirent *entry;

      dir = opendir("../");

      if (dir == NULL){
            printf("Unable to open");
            return 1;
      }
      while (entry = readdir(dir)){
            if (entry->d_type == DT_DIR){
                  //filter
                  if (((strcmp(entry->d_name, ".") == 0) 
                        || (strcmp(entry->d_name, "..")) == 0)){
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

      return 0 ;
}
