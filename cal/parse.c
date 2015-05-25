#include "parse.h"

int is_operator ( char t )
{
  return t == '+' || t == 'x' || t == '/' || t == '-';
}

int next_operator_index ( char* src ,int current)
{
  int i = current;
  while( src[i] != '\0' )
  {
    if(is_operator(src[i]))
    {
      return i;
    }
    i++;
  }
  return -1;
}

char next_operator ( char* src ,int current)
{
  int res = next_operator_index(src, current);
  if(res == 0)
  {
    return '\0';
  } else 
  {
    return src[res];
  }
}

int operator_order ( char op )
{
  switch(op)
  {
    case '+':
    case '-':
     return 1;
    case 'x':
    case '/':
     return 0;
    default:
     printf("Error : invalid operator by order\n");
     return -1;
  }
}

int length ( char* src )
{
  int i = 0;
  while(src[i] != '\0')
  {
    i++;
  }
  return i;
}

int get_operand ( char* src, int start, int last)
{
  int i = 0;
  char buf[255];
  for(i = start; i < last; i++)
  {
    buf[i-start] = src[i];
  }
  buf[i] = '\0';
  return atoi(buf);
}
struct Node* parse    ( char* src )
{
   // Initialize
  char buf[256] ;
  char current_op, next_op;
  int i = 0, eaten = 0;
  struct Node *root, *num, *right_most;
  int op_index = next_operator_index(src,0);
  if(op_index == 0)
  {
    printf("Error: no operator ");
    return NULL;
  }
  current_op = src[op_index];
  root = new_op_node(current_op);
  right_most = root;
  num  = new_val_node(get_operand(src,eaten,op_index));
  eaten = op_index + 1;
  set_left(root,num);

  //main parsing loop
   
  
  op_index = next_operator_index(src,op_index + 1 );
  while(op_index != -1)
  {
    next_op = src[op_index];

    if(operator_order(current_op) < operator_order(next_op))
    {
      struct Node* temp_root;
      temp_root = new_op_node(next_op); 
      temp_root->left = root;
      root->right = new_val_node(get_operand(src,eaten,op_index));
      root = temp_root;
      right_most = root;
    } 
    else
    {
      struct Node* next_node;
      next_node = new_op_node(next_op); 
      right_most->right = next_node;
      next_node->left = new_val_node(get_operand(src,eaten,op_index));
      right_most = next_node;
    }
    current_op = next_op;
    eaten = op_index + 1;
    op_index = next_operator_index(src,op_index + 1);
  }

  right_most->right = new_val_node(get_operand(src,eaten,length(src)));

  return eval(root);
}
