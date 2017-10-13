#include "linked.h"

void print_list(struct node * node){
  printf("%s", "[");
  while (node -> next){
    printf("%d%s", node -> i, ", ");
    node = node -> next;
  }
  printf("%d%s\n", node -> i, "]");
}
struct node * insert_front(struct node * node, int x){
  struct node * temp;
  temp = (struct node *) calloc(1, sizeof(node));
  temp -> i = x;
  temp -> next = node;
  return temp;
}

struct node * free_list(struct node * node){
  free_list(node -> next);
  node -> next = 0;
  free(node);
  return node;
}

int main(){
  struct node * test;
  test = insert_front(0, 17);
  test = insert_front(test, 15);
  test = insert_front(test, 13);
  print_list(test);
  free(test);
  // print_list(test);

  printf("%p\n", test);
}
