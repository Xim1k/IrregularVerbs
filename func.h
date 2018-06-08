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
int game(struct dict dictonary[121], int score);
void print_q(dict dictonary, int from);
int check_ans( dict dictonary, int to, char ans[]);
int checkword(form word);

#endif
