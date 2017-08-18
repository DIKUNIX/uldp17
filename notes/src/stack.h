#ifndef STACK_H
#define STACK_H

#define STACK_UNDERFLOW   3
#define STACK_OVERFLOW    4

struct stack {
  int value;
  struct stack *tail;
};

int stack_push(struct stack **stack, int value);

int stack_peek(struct stack **stack, int *value);

int stack_pop(struct stack **stack, int *value);

#endif // STACK_H
