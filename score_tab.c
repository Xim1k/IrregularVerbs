#define N = 20;
void score_tab( int score );

void score_tab( int score ){
  int i = 0;
  int res[N]
  FILE *f = fopen("result.txt","r" );
  while ( !feof(f) ){
    for( i = 0 ; i < N ; i++ ){
    fscanf( f , "%d" , res[i] );
    }
  }
  fclose(f);

  if( score < res[N] ){
    printf("Sorry, but your result is too low to be there :(");
    return;
  }else{
    res[N] = score;
  }

  int j, n = 0;
  int max;
  max = res[0];
  for (i = 1; i < n; i++) {
    if (max < res[i]) {
      max = res[i];
    }
  }
  max++;
  int b[max];
  for (i = 0; i < max; i++){
    b[i]=0;
  }
  for (i = 0; i < n; i++){
    b[a[i]]++;
  }
  i = 0;
  for (j = 0; j < max; j++){
    while (b[j] > 0){
      a[i] = j;
      i++;
      b[j]= b[j] - 1;
    }
  }
}
