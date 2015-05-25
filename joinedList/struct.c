int main() 
{
  head = (struct Cell*)malloc(sizeof(struct Cell));
  head->value = 3;
  for(int i=0;i<100;++i){
    append(head,i);
  }

  //  printf("head points %x\n",head->next);
  print_all_cell(head);

  free_all(head);
  return 0; 
}
