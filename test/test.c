#include <stdio.h>
#include <stdlib.h>
#define CTEST_MAIN
#include "ctest.h"
#include "../src/func.h"

CTEST(checkword, 99)
{
  //Given
  struct form word;
  word.perc = 99;
  //When
  const int result = checkword(word);
  //Then
  const int expected = 1;
  ASSERT_EQUAL(expected, result);
}

CTEST(checkword, 90)
{
  //Given
  struct form word;
  word.perc = 90;
  //When
  const int result = checkword(word);
  //Then
  const int expected = 1;
  ASSERT_EQUAL(expected, result);
}

CTEST(checkword, 0)
{
  //Given
  struct form word;
  word.perc = 0;
  //When
  const int result = checkword(word);
  //Then
  const int expected = 0;
  ASSERT_EQUAL(expected, result);
}

CTEST(checkword, 50)
{
  //Given
  struct form word;
  word.perc = 50;
  //When
  const int result = checkword(word);
  //Then
  const int expected = 0;
  ASSERT_EQUAL(expected, result);
}

int main (int argc, const char** argv){
  printf("\n\n");
  return ctest_main(argc, argv);
}
