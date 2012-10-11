/********************************************************************
 *
 *           file: check_str.c
 *           author: Vy Nguyen
 *           last-modified: Oct 04 2012
 *
 * This 'implements' the pushdown automaton described here:
 * http://www.cs.umb.edu/~vngu0510/images/state_diagram.gif
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "utils/stack.h"

#define UNKNOWN -1


/*****************************************************************
 * is_accepted
 * 
 * checks whether the input is a string of this form
 * w.w^-1, tthat is, a string which is the concatenation of a string w
 * with its reverse w^-1, using ONLY a stack (and multiple processes)
 *
 * Note: The input itself is stored in a stack, but that's not counted
 *       as 'the second stack'
 *
 *
 * <> input: input string stored in the stack
 *           TODO: change the datastructure of input
 *                 to avoid confusion (of anyone reading the code)
 *                 with the stack used for the computation
 *****************************************************************/
int is_accepted(Stack* input)
{
  char inch;
  char popped;
  Stack* stck;
  int ret = UNKNOWN;
  int pd;

  stck = init_stack();

  while ((inch = pop(input)) != EMPTY_STACK)
  {
    push(stck, inch);
    switch(fork())
    {
        case 0: // child
          while(1)
          {
                inch = pop(input);
                popped = pop(stck);

                if (inch != popped || inch == EMPTY_STACK || popped == EMPTY_STACK)
                  break;
          }

          if (ret = inch == popped)
            printf("ACCEPTED in %d\n", getpid());
          else
            printf("DENINED in %d\n", getpid());

          kill(getpid());
          return ret; 
          // ret; >>> WHY IS IT STILL executed? should've been killed!
        case -1: // failed to fork
          printf("\nFailed to fork\n");
          break;

        default: // parent
          ; // does nothing
    }
  }

  // free the stack
  free_stack(stck);

  return UNKNOWN;
}


/**************************************************
 *
 * Simple main(void) to test the is_accepted()
 *
 *************************************************/
int main(void)
{
  Stack* input;
  int ret;

  // init input
  input = init_stack();
  push(input, '1');
  push(input, '0');
  push(input, '0');
  push(input, '1');

  printf("\nSTART\n");

  ret = is_accepted(input);
  printf("\nRET = %d\n", ret);

  printf("\nEND\n");
  return 0;
}

