#include <stdio.h>
#include "func.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

void score_tab( char name[], int score ){
  int i = 0, j = 0, t = 0;
  char s, players[60];
  int scores[19];
  for( i = 0 ; i < 19 ; i++ ){
    scores[i] = 0;
  }
  FILE *fi;
  fi = fopen("src/results.txt","r" );
  fgets( players , 61 , fi );
  for( i = 0 ; i < 20 ; i++ ){
    fscanf( fi , "%d" , &scores[i] );
  }
  if( feof(fi) ){
    fclose(fi);
  }
  if( score <= scores[19] ){
    printf("Sorry, but your result is too low to be there :(\n");
    return;
  }else{
    players[57] = name[0];
    players[58] = name[1];
    players[59] = name[2];
    scores[19] = score;
  }

  for( i = 19 ; i > 0 ; i-- ){
    if( scores[i] > scores[i-1]){
      t = scores[i-1];
      scores[i-1] = scores[i];
      scores[i] = t;
      j++;
    }else{
      break;
    }
  }
  j = j*3;
  s = players[59];
  players[59] = players[59-j];
  players[59-j] = s;
  s = players[58];
  players[58] = players[58-j];
  players[58-j] = s;
  s = players[57];
  players[57] = players[57-j];
  players[57-j] = s;
  puts(players);
  FILE *fo;
  fo = fopen( "src/results.txt","w" );
  fprintf( fo , "%s" , players );
  fprintf( fo , "\n" );
  for( i = 0 ; i < 20 ; i++ ){
    fprintf( fo , "%d" , scores[i] );
    fprintf( fo , "\n" );
  }
  fclose(fo);
}


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

int game(struct dict dictonary[121]){
  int from;
  int to;
  int check = 1;
  int num;
  char ans[12] = {};
  srand(time(NULL));
  num = 1 + rand() % 121;
  while (check){
    from = 1 + rand() % 3;
    to = from;
    while (to == from) {
      to = 1 + rand() % 3;
    }
    if (to == 1){
      check = checkword(dictonary[num].first);
    }
    if (to == 2){
      check = checkword(dictonary[num].second);
    }
    if (to == 3){
      check = checkword(dictonary[num].third);
    }
  }
  print_q(dictonary[num], from, to);
  scanf("%s", ans);
  if(check_ans(dictonary[num], to,ans)){
    if (to == 1){
      dictonary[num].first.perc = dictonary[num].first.perc + 5;
    }
    if (to == 2){
      dictonary[num].second.perc = dictonary[num].second.perc + 5;
    }
    if (to == 3){
      dictonary[num].third.perc = dictonary[num].third.perc + 5;
    }
    return 1;
  } else {
    printf("Wrong answer!");
    return 0;
  }
}

void print_q(struct dict dictonary, int from ,int to){
  if (to == 1){
      if(from == 2){
        printf("\n\n\n");
        printf("Write the first form %s :", dictonary.second.word);
      }
      if(from == 3 ){
        printf("\n\n\n");
        printf("Write the first form %s :", dictonary.third.word);
      }
  }
  if (to == 2){
    if(from == 1){
      printf("\n\n\n");
      printf("Write the second form %s :", dictonary.first.word);
    }
    if(from == 3 ){
      printf("\n\n\n");
      printf("Write the second form %s :", dictonary.third.word);
    }
  }
  if (to == 3){
    if(from == 2){
      printf("\n\n\n");
      printf("Write the third form %s :", dictonary.second.word);
    }
    if(from == 1 ){
      printf("\n\n\n");
      printf("Write the third form %s :", dictonary.first.word);
    }
  }
}

int check_ans(struct dict dictonary, int to, char ans[]){
  int i = 0;
  while(ans[i] != '\0'){
    i++;
  }
  ans[i]='\n';
  ans[i+1]= '\0';
  if (to == 1){
    if(strcmp(ans, dictonary.first.word) == 0){
      return 1;
    } else {
      return 0;
    }
  }
  if (to == 2){
    if(strcmp(ans, dictonary.second.word) == 0){
      return 1;
    } else {
      return 0;
    }
  }
  if (to == 3){
    if(strcmp(ans, dictonary.third.word) == 0){
      return 1;
    } else {
      return 0;
    }
  }
  return 2;
}

int checkword(struct form word) {
  int n;
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
  return 2;
}

void lowperc( struct dict dictonary[]){
  int i;
  for(i = 0; i <= 120; i++){
    if (dictonary[i].first.perc - 2 >= 0){
      dictonary[i].first.perc = dictonary[i].first.perc - 2;
    }
    if (dictonary[i].second.perc - 2 >= 0){
      dictonary[i].second.perc = dictonary[i].second.perc - 2;
    }
    if (dictonary[i].third.perc - 2 >= 0){
      dictonary[i].third.perc = dictonary[i].third.perc - 2;
    }
  }
}

void printperc(struct dict dictonary[], FILE* percent){
  int i = 0;
  for(i = 0; i <= 120; i++){
    fprintf(percent,"%d\n", dictonary[i].first.perc);
    fprintf(percent,"%d\n", dictonary[i].second.perc);
    fprintf(percent,"%d\n", dictonary[i].third.perc);
  }
}
