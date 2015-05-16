#include "cell.h"

void free_all();

void fatal_error(struct Cell* root){
  printf("fatal error"); 
  free_all(root);
}

struct Cell* new_cell(int val)
{
  struct Cell* c;
  c = (struct Cell*)malloc(sizeof(struct Cell));
  if(c == NULL)
  {
    //fatal_error();
  }
  c->value = val;
  return c;
}

struct Cell* previous_cell(struct Cell* root, struct Cell* c)
{
  if( root == c )
  {
    return NULL;
  }
  else if( root->next == c )
  {
    return root;
  }
  else
  {
    struct Cell* p;
    p = root;
    while(p->next != c)
    {
      if(p->next != NULL)
      {
        p = p->next;
      } 
      else 
      {
        break;
      }
    }
    return p;
  }
}

void dbg ( struct Cell* c )
{
  if(c == NULL)
  {
    printf("cell is null\n");
  } 
  else
  {
    printf("addr : %x, next : %x, value : %d\n", (unsigned int)c, (unsigned int)c->next, c->value);
  }
}

void delete(struct Cell* root, struct Cell* c)
{
  struct Cell* prev = previous_cell(root,c);
  struct Cell* next = NULL;
  if(c->next != NULL)
  {
    next  = c->next;
  } 
  if(prev == NULL)
  {
    printf("ERROR : root cell cannot be deleted\n");
    if(root->next != NULL)
    {
      //ここでrootを消したい
    }
    return;
  }
  if(next == NULL)
  {
    prev->next = NULL; 
  }
  else
  {
    prev->next = next;
  }
  free(c);
}

void append(struct Cell* c, int val)
{
  if(c->next == 0){
    c->next = new_cell(val);
    return;
  }
  struct Cell* ptr = c->next;
  while(ptr->next != 0){
    ptr = ptr->next;
  }
  ptr->next = new_cell(val);
}

struct Cell* _get_cell_by_index_rec(struct Cell* c, int index, int acc)
{
  if(c->next != NULL && acc < index){
    acc++;
    return _get_cell_by_index_rec(c->next,index,acc);
  } else { 
    return c;
  }
}
struct Cell* get_cell_by_index(struct Cell* c,int index)
{
  return _get_cell_by_index_rec(c,index,0);
}

int _length_of_rec(struct Cell* c, int length)
{
  length++;
  if(c->next != NULL){
    return _length_of_rec(c->next,length);
  } else { 
    return length;
  }
}
int length_of(struct Cell* c)
{
  return _length_of_rec(c,0);
}

void _print_all_cell_rec(struct Cell* c, int index)
{
  printf(" #%d, ",index);
  index++;
  if(c->next != NULL){
    printf("addr : %x, next : %x, value : %d\n", (unsigned int)c, (unsigned int)c->next, c->value);
    _print_all_cell_rec(c->next,index);
  } else { 
    printf("addr : %x, next : %x, value : %d\n", (unsigned int)c, (unsigned int)c->next, c->value);
  }
}

void print_all_cell ( struct Cell* c )
{
  _print_all_cell_rec(c, 0);
  printf("there is %d cells\n",length_of(c));
}

void free_all(struct Cell* c)
{
  if(c->next == NULL){
    return;
  } else {
    free_all(c->next);
    free(c);
  }
}

