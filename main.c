#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> // Metodo strlen,

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
bool error;

bool is_digit(char c){

  return (c >= '0' && c <= '9');
}
bool is_operator(char c)
{
  return (c=='+' || c == '-') || (c == '*' || c == '/');
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
    int current_number = c - '0';
    current_pos += 1;
    while (is_digit(text[current_pos])){
      current_number *= 10;
      current_number += (text[current_pos] - '0');
      current_pos += 1;
    }
    current_pos -= 1;
    current_token.type = INT;
    current_token.number_value = current_number;
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
    printf("Invalid token recieved at pos %d: %c\n",current_pos+1, c);
    if (c == '\n') {
      printf("Add an operator or a number\n");
    }
    //exit(EXIT_FAILURE);
    error=true;
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
    //exit(EXIT_FAILURE);
    error = true;
  }
}


double interpret(char *text)
{
  double result=0.0;
  // desde el texto input, creamos tokens:
  // tokenizer( pasa texto a token);
  get_next_token(text); // debe ser un int
  if (error)
    return -1;

  parse(INT);
  if (error)
    return -1;
  result += (double) current_token.number_value;

  int len = strlen(text);
  while (current_pos < len-1){
    get_next_token(text); // debe ser un operador
    if (error)
      return -1;
    parse(OP);
    if (error)
      return -1;
    char operator = current_token.operator_value;

    get_next_token(text); // debe ser un int
    if (error)
      return -1;
    parse(INT);
    if (error)
      return -1;
    double operand = current_token.number_value;


    if (operator == '+')
      result += operand;
    else if (operator == '-')
      result -= operand;
    else if (operator == '*')
        result *= operand;
    else
      result /= operand;
  }
  return result;
}

int main()
{
  char s[INPUT_LENGTH];
  printf("Intrerpreter running...");
    
  double result;
  while (true) 
  {
    error = false;
    current_pos = 0;
    printf(">>> ");
    // No uso scanf porque eso ya es en si mismo
    // un "interprete"
    fgets(s, INPUT_LENGTH, stdin);
    result = interpret(s);
    if (!error)
      printf("%f\n", result);
  }
}
