#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENG 10
typedef unsigned int uint ;

typedef struct{
      char *key ;
      void (*func)(int a,int b);
}hashmap;

hashmap * hastable[LENG] = {NULL};

//todo
//1. hash function where it hash the key argument into a random valuee
//2. use that hashed value as an index for the 


uint hash(char *key){
      uint hashval = 0;
      while(*key){
            hashval += (*key * 31);
            key++;
      }
      return hashval;
}

void insert(char *key, void (*func)(int a, int b)){
      uint index = hash(key) % LENG ;
      printf("%d, %s \n",index, key);


      hashmap *hm = malloc(sizeof(hashmap)); // we allocate a memories in heap
                                             // for the size of hashmap struct, since both of the variable is a pointer and the size of it in 64 bytes system is 8 bytes so we allocate 16 bytes
      hm->key = key;
      hm->func = func;

      //now i understand why hashtable has worst condition of O(N)
      check:
      if (hastable[index] != NULL){
            index += 1;
            if (index >= LENG){
                  index = 0;
            }
            goto check;
      }
      hastable[index] = hm;
}

hashmap *look (char *key){
      int index = hash(key) % LENG ;

      check:
      if ((hastable[index] != NULL)){
            if (strcmp(key, hastable[index]->key) == 0){
                  return hastable[index];
            }

            else{
                  if (index >= LENG){
                        index = 0;
                  }
                  index++;
                  goto check;
            }
      }
      return NULL;
}

void printhash(){
      printf("I \t key \t\t funcaddr\n");
      for (int i = 0 ; i < 10; i++){
            if (hastable[i] == NULL ){
                  printf("%d \t UNALLOCATED\n", i);
                  continue;
            }
            printf("%d \t %s \t\t %p\n",i,hastable[i]->key, hastable[i]->func);
      }
}


//---------------- dummy function
void test(int a, int b){
      printf("%d\n", a + b);
}


void foo(int a, int b){
      printf("%d\n", a + b);
}


void bar(int a, int b){
      printf("%d\n", a + b);
}


int main(){
      insert("mul", test);
      insert("div", foo);
      insert("yadi", test);
      insert("wawan", bar);
      insert("asd", test);
      insert("priya", test);
      insert("warm", test);
      insert("sia", test);
      printhash();
      hashmap *Cari = look("wawan");
      return 0;
      
}
