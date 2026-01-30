#include <stdio.h>
#include <stdbool.h>

#define INPUT_LENGTH 1000

int main()
{
  char s[INPUT_LENGTH];
  printf("Intrerpreter running...");
  while (true) 
  {
    printf(">>> ");
    // No uso scanf porque eso ya es en si mismo
    // un "interprete"
    fgets(s, INPUT_LENGTH, stdin);
  }


}
