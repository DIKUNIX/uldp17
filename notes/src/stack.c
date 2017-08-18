#include <stdlib.h>
#include "stack.h"

int stack_push(struct stack **stack, int value) {
  struct stack *new_stack = (struct stack*)malloc(sizeof(struct stack));

  if (new_stack == NULL) {
    return STACK_OVERFLOW;
  }

  new_stack->value = value;
  new_stack->tail = *stack;

  *stack = new_stack;

  return 0;
}

int stack_peek(struct stack **stack, int *value) {
  if (*stack == NULL) {
    return STACK_UNDERFLOW;
  }

  *value = (*stack)->value;

  return 0;
}

int stack_pop(struct stack **stack, int *value) {
  struct stack *old_stack;

  if (*stack == NULL) {
    return STACK_UNDERFLOW;
  }

  old_stack = *stack;
  *value = old_stack->value;
  *stack = old_stack->tail;

  free(old_stack);

  return 0;
}
