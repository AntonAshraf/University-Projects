/////*********************************************************/////
/////*         Simple Calculator implemented with Stack      */////
/////*         7th mini project Data structre course         */////
/////*  Anton Ashraf. 20105183, Filopateer Fouad. 20106168   */////
/////*          in AAST,Cairo,Egypt         2022             */////
/////*********************************************************/////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include "stack.h"
#include "coloring.h"

bool check_priority (cStack* op ,char c);
int sz_opStack(char infix[]);
void emptyBracket(cStack* op,char postfix[],int *ind);
bool Equal_bracket(cStack *st, char s[]);

// Check Function
bool isOpenBracket(char c);
bool isCloseBracket (char c);
bool isoperator (char c);
bool isBracket(char c);

int main() {
  welcome_screen();
  system("cls");
  char option = '1';

  while (option == '1'){
    system ("cls");
    Cyan();
    printf("\n\n\t\t\tWelcome to our basic calculator that work in PEMDAS (from left to right)");
    white();
    cStack op_Stack;
    iStack evalStack;
    int sz = 0;
    char infix[200] = "";
    char *postfix=NULL;

    printf ("\n\n\tEnter the equation here: ");
    scanf(" %[^\n]s",infix);
    
    postfix = (char*)malloc(sizeof(char) * strlen(infix));
    finitStack(&evalStack,strlen(infix));
    sz=sz_opStack(infix);
    
    if(!cinitStack(&op_Stack,sz)) {
      Red();
      printf ("\tstack cannot be intilized!");
      return 1;
    }


    if(!Equal_bracket(&op_Stack, infix)) {
      Red();
      printf("The Expression is not equal in Brackets\n\n\t %s",infix);
      return 1;
    }
    ////////////////////                        *postfix*                                ////////////////////////
    bool digit = true, op = true;
    int j = 0;
    int outWithError = 0;
    for (int i = 0; i < strlen(infix); i++){
      
      if (infix[i] == ' ')
        continue;
      else if (isoperator(infix[i]) && op == true  && infix[i] == '-') {
        postfix[j++] = '_';
        continue;
      }
      else if (isoperator(infix[i]) && op == true ) {                        // if operator in the begining of the equation "/7"  OR double operator "2+*3", "3*/"
        Red();
        printf ("\t\tUNVALID expression!\n\n\t\t\t%s",infix);
        outWithError = 1;
        break;
      } else if (isCloseBracket(infix[i]) && isdigit(infix[i+1]) || isOpenBracket(infix[i+1]) && isdigit(infix[i])){    
        Red();                                                                 // if number found after close bracket like "(2+2)4+1"
        printf ("\t\tUNVALID number with bracket");
        outWithError = 1;
        break;
      } else if (i == strlen(infix) - 1 && isoperator(infix[i])) {
        Red();
        printf ("\t\tUNVALID operator in the end of the expression!");
        outWithError = 1;
        break;
      } else if (isoperator(infix[i]) && isCloseBracket(infix[i + 1])) {
        Red();
        printf("\n\t\tSyntax Error");
        outWithError = 1;
        break;
      }
    
      if(isdigit(infix[i])) {                                                   // push number to the postfix string
        op = false;
        if (digit == true){
          postfix[j++] = '$';                                                   // Mark the begining of the number 
          digit = false;
        } 
        postfix[j++] = infix[i];
      }  
      else if(isoperator(infix[i]) || isBracket(infix[i])) { 
        if(isoperator(infix[i]))
          digit = op = true;
        if (isOpenBracket(infix[i]))                                             // push open bracket to stack
          cpush(&op_Stack,infix[i]);
        else if (isCloseBracket(infix[i]))                                       // if close bracket found
          emptyBracket(&op_Stack, postfix,&j);                                  
        else {
          while(!check_priority(&op_Stack,infix[i])){                            // Check the power of operator
            postfix[j++]=ctop(&op_Stack);
            cpop(&op_Stack);                                                    // pop weak operator after put it in postfix string
          }
          cpush(&op_Stack,infix[i]);                                            // push the high operator on the right place on stack
        }
      }
      else{                                                                     // if Invalid character like 'a'
        Red();
        printf("\t\tThe expression is not an equation");
        outWithError = 1;
        break;
      }
    }
    
      while (!cisEmpty(&op_Stack)){                                           // pop rest of operators from the stack to postfix string
        postfix[j] = ctop(&op_Stack);
        j++;
        cpop(&op_Stack);
      }
    postfix[j] = '\0';
    if (outWithError == 0) {
      // printf ("%d", outWithError);
      printf("\n\t\tThe postfix: %s\n\n",postfix);
    
      ////////////////////////                      *Evaluation*                                   /////////////////////

      float deci, num;
      int real ,p;                                                               //p counter of the power of the digit
      float x, y;
      bool neg = false;
      for (int i = 0; i < strlen(postfix); i++){
        real = deci = num = neg = 0;
        p=-1;
        if (postfix[i] == '_'){
          neg = true;
          i++;
        }
        if(postfix[i] == '$') {                                                  // if number found!
          i++;
          while (isdigit(postfix[i]) && postfix[i] != '.'){                      // loop to get the real value
            real += (postfix[i] - '0');
            real *= 10;
            i++;
          }
          if (postfix[i] == '.'){
            i++;                                                                  // to skip '.'
            while (!isoperator(postfix[i]) && postfix[i] != '$'){                 // loop to get the decimal value
              deci += (postfix[i] - '0') * pow(10,p);
              p--; 
              i++;
            }
          }
          i--;                                                                    // to delete the last operation of i in the last count in the loop
          real /= 10;                                                             // to delete the increase that happened in the last count in the loop
          num = real + deci;
          if(neg)
            num *= -1;

          fpush (&evalStack,num);
        }
        else {
          fpop (&evalStack,&y);
          fpop (&evalStack,&x);
          if (postfix[i] == '+')                          
            fpush(&evalStack, x + y);                   
          if (postfix[i] == '-')                        
            fpush(&evalStack, x - y);                  
          if (postfix[i] == '*')                       
            fpush(&evalStack, x * y);                 
          if (postfix[i] == '/'){
            if(y == 0){
              Red();
              printf("\t\tMath ERROR!\n");
              return 1;
            }
            fpush(&evalStack, x / y);
          }
          if (postfix[i] == '^'){
            if(x==0&&y==0){
              Red();
              printf("\t\tMath ERROR!\n");
              return 1;
            }
            fpush(&evalStack, pow(x,y));
          }
        }
      }

      float result = 0;
      fpop(&evalStack,&result);

      Green();
      printf ("\tThe answer of the equation is %.2f\n\n", result);
    }else 
      getch();
    offwhite();
    printf ("\n\n\tDo you have another Equation you want calculate? (1/0)  ");
    option = getch();
    while(option != '0' && option != '1'){
      system("cls");
      Red();
      printf("\n\tWrong input");
      offwhite();
      printf ("\n\n\tDo you have another Equation you want calculate? (1/0)  ");
      option = getch();
    }
  }
  system("cls");
  Green();
  printf ("\n\n\n\n\t\t\tThank you :)");

  return 0;
}




bool check_priority (cStack* op ,char c){
  char arr[]="^*+";
  if(cisEmpty(op))                              // Check the stack is empty 
    return true;
  
  char x=ctop(op);

  if(x == '(')                                  // No priority for bracket
    return true;

  if(c == '/')                                  // Conditions to check with operator priority array
    c = '*';
 
  if(c == '-')
    c = '+';

  if(x == '/')
    x = '*';
  
  if(x == '-')
    x = '+';

  for(int i = 0; i < 3; i++){
    if(x == arr[i])                             // Check the top first because of the priority
      return false;
    if(c == arr[i])
      return true;
  } 
}
bool Equal_bracket(cStack *st, char s[]){                 
  for(int i=0;i<strlen(s);i++){
    if(s[i] == '(' || s[i] == '{' || s[i] == '[' )
      cpush(st,s[i]);
    else if(!cisEmpty(st) && s[i] ==')' && ctop (st) == '(')
      cpop(st);
    else if(!cisEmpty(st) && s[i] == ']' && ctop (st) == '[')
      cpop(st);
    else if(!cisEmpty(st) && s[i] =='}' && ctop (st) == '{')
      cpop(st);
    else if (cisEmpty(st) && s[i] == ']' || s[i] == '}' || s[i] == ')') 
      return false;
  }
  if(cisEmpty(st))
    return true;
  else
    return false; 
}
bool isOpenBracket(char c) {                                      
  return (c == '(' || c == '{' ||c == '[');
}
bool isCloseBracket (char c) {
  return (c == ')' || c == ']' ||c == '}');;
}
bool isBracket (char c) {
  return (isCloseBracket(c) || isOpenBracket(c));
}
bool isoperator(char c) {
  return (c == '+' || c == '*' || c == '/' || c == '-' || c == '^' );
}

void emptyBracket(cStack* op,char postfix[],int *ind){
   while (!cisEmpty(op) && !isOpenBracket(ctop(op))){
        postfix[*ind] = ctop(op);
        *ind=*ind+1;
        cpop(op);                                             // pop all opertators
      } 
      cpop(op);                                               // pop the open bracket from stack
}

