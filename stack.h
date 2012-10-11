/*********************************
 *
 *
 *        file: stack.h
 *        author: Vy Nguyen
 *
 *        implements a character stack
 *        TODO: make this 'generic'
 *
 */

#ifndef STACK_H
#define STACK_H

#define EMPTY_STACK -1
typedef struct stack
{
  char ch;
  struct stack* prev;
} Stack;

// pre-cond: 
// post-cond: initialise the stack and return its pointer
extern Stack* init_stack();

// pre-cond
// post-cond: free the stack
extern void free_stack(Stack*);

// pre-cond `init_stack()` has been called before this
// post-cond: a char is popped off the stack and returned here
extern char pop(Stack*);

// pre-cond: `init_stack()` has been called
// post-cond: a char is pushed onto the stack
extern void push(Stack*, char);

#endif
