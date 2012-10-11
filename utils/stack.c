/*****************************************
 *
 *      file: stack.c
 *      author: Vy Nguyen
 *
 *      implementation of the stack
 *
 */

#include "stack.h"
#include "stdlib.h"

Stack* init_stack()
{
  Stack* ret = (struct stack*)malloc(sizeof(struct stack));
  ret->prev = NULL;
  return ret;
}

void free_stack(Stack* stck)
{
  char ch;

  while((ch = pop(stck)) != EMPTY_STACK)
    ; // keep popping the stack until reaching the bottom

  free(stck);
}

char pop (Stack* stck)
{
  char ret;
  if (stck->prev)
  {
    ret = stck->ch;
    Stack* prv = stck->prev;
    stck->prev = prv->prev;
    stck->ch = prv->ch;
    free(prv);
    return ret;
  }
  else
    return EMPTY_STACK;
}

void push (Stack* stck, char ch)
{
  Stack* new_nd = (struct stack*)malloc(sizeof(struct stack));
  
  new_nd->prev = stck->prev;
  new_nd->ch = stck->ch;

  stck->prev = new_nd;
  stck->ch = ch;
}
  


  
