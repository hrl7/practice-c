#include <stdio.h>
struct Cell {
  struct Cell *next;
  int value;
} ;

void fatal_error(struct Cell* root);
struct Cell* new_cell(int val);
void append (struct Cell* c, int val);
void print_all_cell ( struct Cell* c );
void free_all (struct Cell* c);
int length_of(struct Cell* c);
struct Cell* get_cell_by_index(struct Cell* c, int index);
void delete (struct Cell* root, struct Cell* c);
struct Cell* previous_cell(struct Cell* root, struct Cell* c);
void dbg ( struct Cell* c );
