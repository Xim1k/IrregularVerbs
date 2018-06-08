#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void score_tab( char name[], int score ){
  int i = 0, j = 0, t = 0;
  char s, players[60];
  int scores[19];
  for( i = 0 ; i < 19 ; i++ ){
    scores[i] = 0;
  }
  FILE *fi;
  fi = fopen("result.txt","r" );
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
  fo = fopen( "result.txt","w" );
  fprintf( fo , "%s" , players );
  fprintf( fo , "\n" );
  for( i = 0 ; i < 20 ; i++ ){
    fprintf( fo , "%d" , scores[i] );
    fprintf( fo , "\n" );
  }
  fclose(fo);
}
