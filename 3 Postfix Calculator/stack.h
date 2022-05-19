#ifndef STACK_H
#define STACK_H

struct cStack{
  char* arr;
  int sp;
  int size;

  cStack(){
    arr = NULL;
    int sp = -1;
    int size = 0;
  }
};

struct iStack{
  float* arr;
  int sp;
  int size;

  iStack(){
    arr = NULL;
    int sp = -1;
    int size = 0;
  }
};

bool isdigit (char c) {
  return (c >= '0' && c <= '9' || c == '.');
}

int sz_opStack(char infix[]){
  int size = 0;
  for (int i = 0; i < strlen(infix); i++)                         // Read number of the operator
    if (isdigit(infix[i]))                                        // if char is operator
      size++;
  return size;                                                    // size of stack
}
bool cinitStack (cStack *s, int n) {
  if(s->arr != NULL)
    free(s->arr);
  s->arr = (char*)malloc(sizeof(char) * n);
  if (s->arr == NULL)
    return false;
  s->size = n;
  s->sp = -1;
    return true;
}
int cpush (cStack* s, char item) {
  if(s->arr == NULL) 
    return -1;
  else if(s->sp +1  == s->size) 
    return -2;
  s->sp++;
  s->arr[s->sp] = item;
  return 0;
}
int cpop(cStack *s) {
  if (s->arr == NULL)
    return -1;
  if (s->sp == -1)
    return -2;
  s->sp--;
  return 0;
}
char ctop(cStack* s) {
  return  s->arr[s->sp];
}
bool cisEmpty(cStack* op) {
  if(op->sp == -1)
    return true;
  return false;
}


bool finitStack (iStack *s, int n) {
  if(s->arr != NULL)
    free(s->arr);
  s->arr = (float*)malloc(sizeof(float) * n);
  if (s->arr == NULL)
    return false;
  s->size = n;
  s->sp = -1;
    return true;
}
int fpush (iStack* s, float item) {
  if(s->arr == NULL) 
    return -1;
  else if(s->sp +1  == s->size) 
    return -2;
  s->sp++;
  s->arr[s->sp] = item;
  return 0;
}
int fpop(iStack *s, float *item) {
  if (s->arr == NULL)
    return -1;
  if (s->sp == -1)
    return -2;
  *item = s->arr[s->sp];
  s->sp--;
  return 0;
}


#endif