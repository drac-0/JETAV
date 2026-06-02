# SHA256 explained + comparison logic

## SHA256
take a look at this section of my code from sha.c

### Padding

```
void *Greg_bitLOC(unsigned char * Sinput, int len){
      unsigned char * gBIT= calloc(512, 1); 
      int i = 0; //allocation for the input bit for (; i < len; i++){ gBIT[i] = Sinput[i]; }
      //printf("\n");
      gBIT[len] = 0x80 ;//(128 in decimal with bin representation of 10000000);

      u64t bitLen = (u64t)len * 8;
      //process of merge bitlen into the main padding
      //i will stick my note with this later
      gBIT[56] = (bitLen >> 56) & 0xFF;
      gBIT[57] = (bitLen >> 48) & 0xFF;
      gBIT[58] = (bitLen >> 40) & 0xFF;
      gBIT[59] = (bitLen >> 32) & 0xFF;
      gBIT[60] = (bitLen >> 24) & 0xFF;
      gBIT[61] = (bitLen >> 16) & 0xFF;
      gBIT[62] = (bitLen >> 8)  & 0xFF;
      gBIT[63] = (bitLen)       & 0xFF; 
      
      //i will get rid of this visualization later
      /*
      for (int j = 0 ; j < 64; j++ ){
            if (j % 4 == 0 ){
                  printf("\n");
            }
            binV(gBIT[j]);
      }
      printf("\n");
      */
      return gBIT;
```


The initial step to perform SHA256 hashing is to create a padding with length of 512 bit

furthermore we will subtract the 512 padding into 3 section
1. unsigned char input binary 
2. 0 padding with the first section set to 1
3. 64 bit for length of input

in my sha.c program, it all happen in a function called Greg_bitLOC (line 69)

before heading to the next part, i am obligated to explain about 1 thing first

### Function requirement


