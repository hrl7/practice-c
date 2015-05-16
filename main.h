#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cell.h"



char* operator[64] = {
  "print all cell",
  "append cell",
  "delete cell"
};
void show_start_message();
void show_choices(char** messages);
void dispatch_action(int op);
void append_op();
void delete_op();

