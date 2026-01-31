#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INPUT_LENGTH 1000

#define INT 0
#define OP 1
#define INT_STR "INT"
#define OP_STR "OP"

typedef struct{
  int type; // puede ser INT o OP
  char operator_value;
  int number_value;
}Token;

int current_pos=0;
Token current_token;

bool is_digit(char c){

  return (c >= '0' && c <= '9');
}
bool is_operator(char c)
{
  return c=='+' || c == '-';
}
bool is_whitespace(char c)
{
  return c == ' ';
}


// obtiene el token actual y avanza el puntero de current_pos
void get_next_token(char *text)
{
  char c = text[current_pos];
  while (is_whitespace(c)){
    current_pos += 1;
    c = text[current_pos];
  }

  if (is_digit(c)){
    current_token.type = INT;
    current_token.number_value = c - '0';
    current_token.operator_value = ' ';
    // Cada char tiene su valor decimal,
    // el y los valores de los numeros estan seguidos
    // por eso devuelve el numero correcto esta resta
  }
  else if (is_operator(c)){
    current_token.type = OP;
    current_token.number_value = 0;
    current_token.operator_value = c;
  }
  else{
    printf("Invalid token recieved at pos %d: %c\n",current_pos, c);
    exit(EXIT_FAILURE);
  }
  current_pos += 1;
}

// Representa el token como un string s
void token_to_str(Token token, char *s)
{
  sprintf(s, "Token (type=%s, number_value=%d, operator_value=%c)",token.type == INT ? INT_STR: OP_STR, token.number_value, token.operator_value);
}


void parse(int type){
  if (current_token.type != type)
  { //PASAR A STRING EL VALOR DEL TOKEN PARA ENTENDER EL ERROR
    char s[100];
    token_to_str(current_token, s);
    printf("Syntax error at pos %d: Expected token of type %s, but recieved %s\n",current_pos, type == INT ? INT_STR : OP_STR, s);
    exit(EXIT_FAILURE);
  }
}
int interpret(char *text)
{
  // desde el texto input, creamos tokens:
  // tokenizer( pasa texto a token);
  get_next_token(text); // debe ser un int
  parse(INT);
  int left = current_token.number_value;
  
  get_next_token(text); // debe ser un operador
  parse(OP);
  char operator = current_token.operator_value;

  get_next_token(text); // debe ser un int
  parse(INT);
  int right = current_token.number_value;

  current_pos = 0;

  int result;
  if (operator == '+')
    result = left + right;
  else
    result = left - right;
  return result;
}

int main()
{
  char s[INPUT_LENGTH];
  printf("Intrerpreter running...");
    
  int result;
  while (true) 
  {
    printf(">>> ");
    // No uso scanf porque eso ya es en si mismo
    // un "interprete"
    fgets(s, INPUT_LENGTH, stdin);
    result = interpret(s);
    printf("%d\n", result);
  }
}
