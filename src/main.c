#include <stdio.h>
#include <string.h>
#include "func.h"
#include <stdlib.h>

int main(){
  char start[6];
  char name[3];
  int score = 0;
  struct dict dictonary[121];
  int wrong;
  int result;

  FILE* fin = fopen("src/words.txt", "r");
  FILE* percent = fopen("src/percent.txt","r");


  printf("\t\tWELCOME\n MENU:\n START\n EXIT\n ");
  scanf("%s", start);
  if ((strcmp(start, "Start") == 0) || (strcmp(start, "start") == 0) || (strcmp(start, "START") == 0)){
    printf("Input your name (Max size - 3):");
    scanf("%s", name);
    create_dict(dictonary, fin, percent);
    while(wrong != 3){
      result = game(dictonary);
      if(result == 1){
        printf("Attempts: %d", 3-wrong);
        score++;
      } else {
        printf("\nAttempts: %d", 3-wrong);
        wrong++;
      }
      printf("\nYour score: %d\n", score);
    }
  } else {
    if ((strcmp(start, "Exit") == 0) || (strcmp(start, "exit") == 0) || (strcmp(start,"EXIT") == 0)){
      exit(1);
    } else {
      printf("Input right word\n");
    }
  }
  score_tab(name, score);
  fclose(percent);
  lowperc(dictonary);
  FILE* perc = fopen("src/percent.txt", "w");
  printperc(dictonary, perc);
  fclose(perc);
  fclose(fin);
  exit(1);
}
