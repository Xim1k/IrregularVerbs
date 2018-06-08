#include<stdio.h>

void score_tab( int score ){
  int i = 0;
  int n = 20;
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

  int j;
  int max;
  max = res[0];
  for (i = 1 ; i < 20 ; i++) {
    if (max < res[i]) {
      max = res[i];
    }
  }
  max++;
  int b[max];
  for (i = 0 ; i < max ; i++){
    b[i] = 0;
  }
  for (i = 0 ; i < n ; i++){
    b[res[i]]++;
  }
  i = 0;
  for (j = max - 1 ; j > 0 ; j--){
    while (b[j] > 0){
      res[i] = j;
      i++;
      b[j]= b[j] - 1;
    }
  }
  FILE *fo;
  fo = fopen( "result.txt","w" );
  for( i = 0 ; i < n ; i++ ){
    fprintf( fo , "%d" , res[i] );
    fprintf( fo , "\n" );
  }
  fclose(fo);
}
