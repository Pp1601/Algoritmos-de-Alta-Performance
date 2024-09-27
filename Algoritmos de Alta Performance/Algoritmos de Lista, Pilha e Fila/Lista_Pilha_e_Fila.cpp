#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 10

//Lista--------------------------------------------------------------------------
/* Ordenamento de dados em modelo de lista
*/
struct node{
  int data;
  struct node* next;
};

typedef struct node Node;

Node* head = NULL;

void insert(int data){
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

void print_list(){
Node* current = head;
  while(current != NULL) {
    printf("%d", current->data);
      current = current->next;
  }
  printf("\n");
}

/*Percore a lista procurando pelo número 5
*/
void print_list_ex(){
Node* current = head;
  while(current != NULL) {
    if(current->data != 5){
      printf("\n%d, não é o número 5!\nPonteiro: %d\n", current->data, current->next);
    }
    else{
      printf("\n%d, é o número 5!\nPonteiro: %d\n", current->data, current->next);
    }
      current = current->next;
  }
  printf("\n");
}
//-------------------------------------------------------------------------------
//Pilha--------------------------------------------------------------------------
/* Ordenamento de dados em modelo de pilha
*/
int top = -1;
int stack[MAX_SIZE];

void push(int data){
  if(top == MAX_SIZE - 1){
    printf("Stack overflow\n");
    return;
  }
  stack[++top] = data;
}

void pop(){
  if(top == -1){
    printf("Stack underflow\n");
    return;
  }
  printf("Element popped: %d\n", stack[top--]);
}

void print_stack(){
  printf("Stack: ");
  for(int i = top; i >= 0; i--){
    printf("%d ", stack[i]);
  }
  printf("\n");
}
//-------------------------------------------------------------------------------
//Fila---------------------------------------------------------------------------
/* Ordenamento de dados em modelo de fila
*/
int front = -1, rear = -1;
int queue[MAX_SIZE];

void enqueue(int data){
  if (rear == MAX_SIZE - 1){
    printf("Queue overflow\n");
    return;
  }
  if (front == -1){
    front = 0;
  }
  queue[++rear] = data;
}

void dequeue() {
  if (front == -1 || front > rear){
    printf("Queue underflow\n");
    return;
  }
  printf("Element dequeued: %d\n", queue[front++]);
  if (front > rear) {
    front = rear = -1;
  }
}

void print_queue(){
  if (front == -1){
    printf("Queue is empty\n");
    return;
  }
  else{
    printf("Queue: ");
    for(int i = front; i <= rear; i++){
      printf("%d ", queue[i]);
   }
  printf("\n");  
  }
}
//-------------------------------------------------------------------------------

int main() {

  setlocale(LC_ALL,"Portuguese");

  insert(1);
  insert(2);
  insert(3);
  insert(4);
  insert(5);
  print_list();
  print_list_ex();

  printf("\n-------------------------------------------------------------------\n\n");
  
  push(1);
  push(2);
  push(3);
  print_stack();
  pop();
  print_stack();
  
  printf("\n-------------------------------------------------------------------\n\n");

  enqueue(1);
  enqueue(2);
  enqueue(3);
  print_queue();
  dequeue();
  print_queue();
  
  printf("\n-------------------------------------------------------------------\n\n");

  return 0;
  
}
