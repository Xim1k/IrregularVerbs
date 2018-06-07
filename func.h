#ifndef FUNC_H
#define FUNC_H

struct dict{
  form first;
  form second;
  form third;
}

struct form{
  char word[12];
  int perc;
}

void create_dict( struct dict dictonary[121], FILE* fin);

#endif
