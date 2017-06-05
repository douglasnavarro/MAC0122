#include <stdio.h>
#include "STACKD.h"
#include <string.h>

/*
We will use two stacks:

Operand stack: to keep values (numbers)  and

Operator stack: to keep operators (+, -, *, . and ^).

In the following, “process” means,
(i) pop operand stack once (value1)
(ii) pop operator stack once (operator)
(iii) pop operand stack again (value2)
(iv) compute value1 operator  value2
(v) push the value obtained in operand stack.

Algorithm:

Until the end of the expression is reached, get one character and perform only one of the steps (a) through (f):

(a) If the character is an operand, push it onto the operand stack.

(b) If the character is an operator, and the operator stack is empty then push it onto the operator stack.

(c) If the character is an operator and the operator stack is not empty, and the character's precedence is greater than the precedence of the stack top of operator stack,
then push the character onto the operator stack.

(d) If the character is "(", then push it onto operator stack.

(e) If the character is ")", then "process" as explained above until the corresponding "(" is encountered in operator stack.  At this stage POP the operator stack and ignore "(."

(f) If cases (a), (b), (c), (d) and (e) do not apply, then process as explained above.

 When there are no more input characters, keep processing until the operator stack becomes empty.  The values left in the operand stack is the final result of the expression.
*/

int main(int argc, char * argv[])
{
  char *a = argv[1];
  int x, y, i, op;
  int N = strlen(a);
  STACKinit(N);
  char P[256];
  P['('] = 0;
  P['+'] = 1;
  P['*'] = 2;

  for(i = 0; i < N; i++)
  {
    if(a[i] >= '0' && a[i] <= '9')
      STACKpush(0, a[i] - '0');
    if( (a[i] == '+' || a[i] == '*') && STACKempty(1))
      STACKpush(a[i], 1);
    if( (a[i] == '+' || a[i] == '*') && !STACKempty(1) && P[a[i]] > P[STACKtop(1)])
      STACKpush(a[i], 1);
    if(a[i] == '(')
      STACKpush(a[i], 1);
    if(a[i] == ')')
    {
      x  = STACKpop(0);
      op = STACKpop(1);
      y  = STACKpop(0);
      if(op == '*')
        STACKpush(x*y, 0);
      if(op == '+')
        STACKpush(x+y, 0);
    }
    else
    {
      while(STACKempty(1) != 1)
      {
        x  = STACKpop(0);
        op = STACKpop(1);
        y  = STACKpop(0);
        if(op == '*')
          STACKpush(x*y, 0);
        if(op == '+')
          STACKpush(x+y, 0);
      }
    }
  }
  while(STACKempty(0) != 1)
  {
    printf("%d", STACKpop(0));
  }
}
