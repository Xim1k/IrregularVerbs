#include <stdio.h>
#include "func.h"
#include <string.h>
#include <stdlib.h>

void create_dict( struct dict dictonary[121], FILE* words, FILE* percent) {
  int i = 0;
  int j = 0;
  char perc[3] = 0;
   while(feof(words)!=0){
     j = 0
     i = 0;
     numb = 0;
     fread(words,"%s", string);
     while((string[i] != '-')){
       dictonary[numb].first.word[j] = string[i];
       j++
       i++;
     }
     j = 0;
     i++;
     while((string[i] != '-')){
       dictonary[numb].second.word[j] = string[i];
       j++
       i++;
     }
     j = 0;
     i++;

     while((string[i] != '-')){
       dictonary[numb].third.word[j] = string[i];
       j++
       i++;
     }
     j = 0;
     i = 0;
   }
   while(feof(percent)!=0){
     fread(percent,"%d", dictonary[i].first.perc);
     fread(percent,"%d", dictonary[i].second.perc);
     fread(percent,"%d", dictonary[i].third.perc);
     i++;
   }
}
