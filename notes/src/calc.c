#include <stdio.h>
#include <ctype.h>

#include "stack.h"

#define EXIT_OP       1
#define INVALID_CHAR  2

typedef int(*binop)(int,int);

int plus(int x, int y) {
  return x + y;
}

int minus(int x, int y) {
  return x - y;
}

int times(int x, int y) {
  return x * y;
}

int div(int x, int y) {
  return x / y;
}

int performBinOp(struct stack **stack, char op, binop binop) {
  int retval, x, y;

  retval = stack_pop(stack, &x);
  if (retval != 0) return retval;

  retval = stack_pop(stack, &y);
  if (retval != 0) return retval;

  retval = stack_push(stack, x * y);

  return 0;
}

// returns an integer indicating whether we should continue to interact
int interact(struct stack **stack) {
  int value;
  char op;
  int retval;

  printf("> ");

  do {
    op = getc(stdin);
  } while (isspace(op));

  switch (op) {
  case '+':
    retval = performBinOp(stack, op, plus);
    break;
  case '-':
    retval = performBinOp(stack, op, minus);
    break;
  case '*':
    retval = performBinOp(stack, op, times);
    break;
  case '/':
    retval = performBinOp(stack, op, div);
    break;
  case 'e':
    retval = EXIT_OP;
    break;
  case 'p':
    retval = stack_peek(stack, &value);
    if (retval != 0) break;

    printf("%d\n", value);
    break;
  default:
    ungetc(op, stdin);
    if (scanf("%d", &value) == 1) {
      retval = stack_push(stack, value);
    } else {
      retval = INVALID_CHAR;
    }
  }

  return retval;
}

int main() {
  struct stack *stack = NULL;

  int retval;
  char cont;

  cont = 1;
  while(cont) {
    retval = interact(&stack);
    switch (retval) {
    case EXIT_OP:
      cont = 0;
      break;
    case INVALID_CHAR:
      printf("Invalid char!\n");
      break;
    case STACK_UNDERFLOW:
      printf("Stack underflow!\n");
      break;
    case STACK_OVERFLOW:
      printf("Stack overflow!\n");
      break;
    default:
      continue;
    }
  }

  return 0;
}
