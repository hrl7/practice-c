#include "node.h"


void dbgN ( struct Node* node)
{
  if(node != NULL )
  {
   if(node->t== VALUE)
   {
    printf("addr: %p\nvalue : %d \ntype : %d\nleft :%p\nright %p\n",
        node, node->value, node->t, node->left, node->right);   
   }
   else
   {
    printf("addr: %p\noperator: %c \ntype : %d\nleft :%p\nright %p\n",
        node, node->value, node->t, node->left, node->right);   
   }
  }
};
int eval  ( struct Node* root)
{
  if(root->t == VALUE)
  {
    return root->value;
  } else {
    switch(root->value)
    {
      case '+': return eval(root->left) + eval(root->right);break;
      case 'x': return eval(root->left) * eval(root->right);break;
      case '-': return eval(root->left) - eval(root->right);break;
      case '/': return eval(root->left) / eval(root->right);break;
      default:
                printf("Invalid Operator\n");
    }
  }

}

void dbgTree(struct Node* root)
{
 if(root == NULL)
 {
    printf("===============ERROR\n");
    return;
 }
  if(root->t == VALUE)
  {
    printf("value :%d\n",root->value); 
  }
  else
  {
   if(root->left == NULL){
    printf("left missing\n");
   }
   if(root->right== NULL){
    printf("rightmissing\n");
   }
   printf("op : %c\n",root->value);
   printf("|left\nv\n");
    dbgTree(root->left);
   printf("|right\nv\n");
    dbgTree(root->right);
  }
}

struct Node* __new_node   ( int val, struct Node* left, struct Node* right, enum Type type )
{
  struct Node* c = (struct Node*)malloc(sizeof(struct Node));
  c->value = val;
  c->left = left;
  c->right = right;
  c->t = type;
  return c;
}
struct Node* new_op_node  ( int op )
{
  return __new_node(op,NULL,NULL,OPERATOR);
}
struct Node* new_val_node ( int val )
{
  return __new_node(val,NULL,NULL,VALUE);
}

void         set_right    ( struct Node* root,  struct Node* right )
{
  if(root == NULL)
  {
    printf("ROOT IS NOT EXIST");
    return;
  }
  root->right = right;
}
void         set_left     ( struct Node* root,  struct Node* left )
{
  if(root == NULL)
  {
    printf("ROOT IS NOT EXIST");
    return;
  }
  root->left = left;
}
