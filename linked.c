//Charles Weng
//Systems Period 4
//HW6 -- Enlist Your C Skillz
//2017-10-16
#include "linked.h"

// go through each node and print out its value and terminates with a \n
void print_list(struct node * node){
  // loop through the list
  while (node){
    printf("%d ", node -> i);
    node = node -> next;
  }
  printf("\n");
}

// insert a value to the front of the list
struct node * insert_front(struct node * node, int x){
  // make the new head of the list
  struct node * temp;
  temp = (struct node *) malloc(sizeof(node));
  // set its values
  temp -> i = x;
  temp -> next = node;
  return temp;
}

// clears the list's memory
struct node * free_list(struct node * node){
  //if this isn't null then clear it and free it
  if(node){
    //recursive call to loop through list
    free_list(node -> next);
    free(node);
  }
  // returns a null pointer since the list is now free
  // only the head's free_list return is used
  return 0;
}

int main(){
  struct node * test;
  test = insert_front(0, 17);
  print_list(test);
  test = insert_front(test, 15);
  test = insert_front(test, 13);
  print_list(test);
  test = free_list(test);
  print_list(test);
  test = insert_front(test, 15);
  test = insert_front(test, 15);
  print_list(test);

  printf("%p\n", test);
}
