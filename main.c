#include <stdio.h>
#include <string.h>


int main(){
  char start[6];
  char name[10];
  int score = 0;
  FILE* fin, fout;

  fin = fopen("words.txt", "r");
  fout = fopen("results.txt", "a");
  

  printf("\t\tWelcome\n Menu:\n Start\n Exit\n ");
  scanf("%s", start);
  if ((strcmp(start, "Start") == 0) || (strcmp(start, "start") == 0)){
    printf("Input your name (Max size - 10):");
    scanf("%s", name);
    while (k = 0){
      k = game (name,score);
      if (k = 0) {
        score++;
      }
    }
  } else {
    if ((strcmp(start, "Exit") == 0) || (strcmp(start, "exit") == 0) || (strcmp(start,"EXIT") == 0)){
      exit(1);
    } else {
      printf("Input right word\n");
    }
  }
}
