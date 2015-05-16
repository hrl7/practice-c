#include "main.h"
struct Cell* root;

int main()
{
  root = new_cell(0);
  append(root,20);
  append(root,30);

  int  result;
  char buf[256];
  show_start_message();
  show_choices(operator);
  result = scanf("%s",buf);

  while( result != EOF){
    printf(" === %s\n",buf);
    {
      //   printf("==key pushed: %x, %d, %c\n", choice,choice,atoi(&choice));
      int op = atoi(buf);
      if(op < 3 && op >= 0)
      {
        dispatch_action(op);
      }
      else
      {
        printf("!!!Invalid action!!!!\n");
      }
      printf("==>");
    }
    result = scanf("%s",buf);
  }
  printf("Bye-bye\n");
}

void dispatch_action(int op)
{
  switch(op)
  {
    case 0: // print all cell
      print_all_cell(root);
      break;
    case 1: // append cell
      append_op();
      break;
    case 2: // delete cell
      delete_op();
      break;
    default :
      show_choices(operator);
      printf("ERROR\n");
  }
}

void append_op()
{
  printf("What do you append? (number)\n==>");
  char arg[256];
  scanf("%s",arg);
  printf(" appended %d \n",atoi(arg));
  append(root, (unsigned int)atoi(arg));

}

void insert_op()
{
  printf("Where do you insert? (number)\n==>");
  char arg[256];
  scanf("%s",arg);
  int id = atoi(arg);
  if(id < length_of(root))
  {
    struct Cell* current_cell = get_cell_by_index(root,id); 
    printf("Cell set\n");
  } 
  else 
  {
    printf("There is no cell at %d\n",id);
  }
}

void delete_op()
{
  printf("What cell do you delete? (number)\n==>");
  char arg[256];
  scanf("%s",arg);
  int id = atoi(arg);
  if(id < length_of(root))
  {
    delete(root, get_cell_by_index(root,id));
  } 
  else 
  {
    printf("There is no cell at %d\n",id);
  }

}

void show_choices(char** messages)
{
  int i , length = sizeof(messages);
  for(i=0; i<length; i++)
  {
    if(messages[i] != NULL){
      printf("%d) %s\n",i,messages[i]);
    }
  }
}

void show_start_message()
{
  printf("Hello, world!\n");
}
