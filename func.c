#include <stdio.h>
#include "func.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

void create_dict(struct dict dictonary[121], FILE* words, FILE* percent) {
   int i = 0;
 while (feof(words) == 0){
   fgets(dictonary[i].first.word, 12, words);
   fgets(dictonary[i].second.word, 12, words);
   fgets(dictonary[i].third.word, 12, words);
   i++;
 }
 i = 0;
 while ( feof(percent) == 0){
   fscanf(percent, "%d", &dictonary[i].first.perc);
   fscanf(percent, "%d", &dictonary[i].second.perc);
   fscanf(percent, "%d", &dictonary[i].third.perc);
   i++;
 }
}

int game(struct dict dictonary[121], int score){
  int from;
  int to;
  int check = 1;
  int numb;
  int q2, q1;
  char ans[12];
  srand(time(NULL));
  numb = 1 + rand() % 121;
  while (check){
    from = 1 + rand() % 3;
    to = from;
    while (to == from) {
      to = 1 + rand() % 3;
    }
    if (to == 1){
      check = checkword(dictonary[numb].first);
    }
    if (to == 2){
      check = checkword(dictonary[numb].second);
    }
    if (to == 3){
      check = checkword(dictonary[numb].third);
    }
  }
  print_q(dictonary[numb], from);
  scanf("%s", ans);
  if(check_ans(dictonary[numb], to, ans)){
    return 1;
  } else {
    printf("Wrong answer!");
    return 0;
  }
}

void print_q(dict dictonary, int from){
  if (from == 1){
      printf("\n\n\n");
      printf("Write the second form %s :", dictonary.first);
  }
  if (from == 2){
      printf("\n\n\n");
      printf("Write the second form %s :", dictonary.second);
  }
  if (from == 3){
      printf("\n\n\n");
      printf("Write the second form %s :", dictonary.third);
  }
}

int check_ans( dict dictonary, int to, char ans[]){
  if (to == 1){
    if(strcmp(ans, dictonary.first) == 0){
      return 1;
    } else {
      return 0;
    }
  }
  if (to == 2){
    if(strcmp(ans, dictonary.second) == 0){
      return 1;
    } else {
      return 0;
    }
  }
  if (to == 3){
    if(strcmp(ans, dictonary.third) == 0){
      return 1;
    } else {
      return 0;
    }
  }
}

int checkword(form word) {
  if(word.perc >= 90){
    return 1;
  }
  if((word.perc >= 75) && (word.perc < 90)){
    srand(time(NULL));
    n = 0 + rand() % 1;
    if(n == 1){
      return 0;
    } else {
      return 1;
    }
  }
  if(word.perc < 75){
    return 0;
  }
}
