#ifndef FUNC_H
#define FUNC_H

struct form{
  char word[12];
  int perc;
};

struct dict{
  struct form first;
  struct form second;
  struct form third;
};


void create_dict(struct dict dictonary[121], FILE* words, FILE* percent);
int game(struct dict dictonary[121]);
void print_q(struct dict dictonary, int from, int to);
int check_ans(struct dict dictonary, int to, char ans[]);
int checkword(struct form word);
void lowperc( struct dict dictonary[]);
void printperc(struct dict dictonary[], FILE* percent);
void score_tab( char name[], int score);
#endif
