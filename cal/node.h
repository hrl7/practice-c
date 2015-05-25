#include <stdio.h>
#include <stdlib.h>
enum Type 
{
  VALUE,
  OPERATOR
};

struct Node 
{
  struct Node *left;  
  struct Node *right;  
  int value;
  enum Type t;
};


void          dbgN        ( struct Node* node );
void          dbgTree     ( struct Node* root );
int           eval        ( struct Node* root );
struct Node* __new_node   ( int val, struct Node* left, struct Node* right, enum Type type );
struct Node* new_op_node  ( int op );
struct Node* new_val_node ( int val );
void         set_right    ( struct Node* root,  struct Node* right );
void         set_left     ( struct Node* root,  struct Node* left );
