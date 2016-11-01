#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void print_list(node *n) {
  printf("[ ");
  while(n) {
    printf("%d ", n->data);
    n = n->next;
  }
  printf("]\n");
}

node * insert_front(node *n, int d) {
  node *new = (node *)malloc(sizeof(node));
  new->next = n;
  new->data = d;
  return new;
}

node * free_list(node *n) {
  node *f = n;
  while (n) {
    n = n->next;
    free(f);
    f = n;    
  }
  return n;
}

int main() {
  node *list = 0;
  print_list( list );
  int i;
  for (i = 0; i < 10; i++)
    list = insert_front(list,i);
  print_list( list );
  list = free_list( list );
  print_list( list );
  return 0;
}
