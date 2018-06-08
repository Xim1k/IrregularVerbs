#include<stdio.h>

void score_tab( int score ){
  int i = 0, t = 0;
  int res[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  FILE *fi;
  fi = fopen("result.txt","r" );
  for( i = 0 ; i < 20 ; i++ ){
    fscanf( fi , "%d" , &res[i] );
  }
  if( feof(fi) ){
    fclose(fi);
  }
  if( score <= res[19] ){
    printf("Sorry, but your result is too low to be there :(\n");
    return;
  }else{
    res[19] = score;
  }

  for( i = 19 ; i > 0 ; i-- ){
    if( res[i] > res[i-1]){
      t = res[i-1];
      res[i-1] = res[i];
      res[i] = t;
    }
  }

  FILE *fo;
  fo = fopen( "result.txt","w" );
  for( i = 0 ; i < 20 ; i++ ){
    fprintf( fo , "%d" , res[i] );
    fprintf( fo , "\n" );
  }
  fclose(fo);
}
