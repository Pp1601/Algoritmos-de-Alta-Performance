#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

struct node {
  int data;
  struct node* left;
  struct node* right;

  };
//Queue-----------------------------------------------------------------------------------
struct QNode {
  struct node* data;
  struct QNode* next;
  };

struct Queue {
  struct QNode* front;
  struct QNode* rear;
};

//Fun��o para criar uma nova fila vazia
struct Queue* createQueue(){
  struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
  q->front = NULL;
  q->rear = NULL;
  return q;
}
//-------------------------------------
//Fun��o para verificar se a fila esta vazia
int isEmpty(struct Queue* q){
  return(q->front == NULL);
}
//-------------------------------------
//Fun��o para adicionar � queue
void enqueue(struct Queue* q, struct node* root){
  
  struct QNode* newNode = (struct QNode*)malloc(sizeof(struct QNode));
  newNode->data = root;
  newNode->next = NULL;

  if(isEmpty(q)){
    q->front = newNode;
    q->rear = newNode;
  }
  else {
    q->rear->next = newNode;
    q->rear = newNode;
  }
}
//-------------------------------------
//Fun��o para remover da queue
void dequeue(struct Queue* q){
  if(isEmpty(q)){
    printf("A fila est� vazia.\n");
  }
  else{
    struct QNode* nodeToRemove = q->front;
    struct node* data = nodeToRemove->data;
    free(nodeToRemove);
    q->front = q->front->next;
    if(q->front == NULL){
      q->rear = NULL;
    }
  }
}
//Tree------------------------------------------------------------------------------------

//Fun��o para criar n�dulos na �rvore
  struct node* create_node(int data){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }
//Fun��o para inserir dados na �rvore
  struct node* insert(struct node* root, int data){
    if(root == NULL){
      return create_node(data);
    }
    if(data < root->data){
      root->left = insert(root->left, data);
    }
    else if(data > root->data){
      root->right = insert(root->right, data);
    }
    return root;
  }
//Percursos de travessia em profundidade
  void inorder_traversal(struct node* root){
    if (root != NULL){
      inorder_traversal(root->left);
      printf("%d ", root->data);
      inorder_traversal(root->right);
    }
  }

   void preorder_traversal(struct node* root){
    if (root != NULL){
      printf("%d ", root->data);
      preorder_traversal(root->left);
      preorder_traversal(root->right);
    }
  }

   void postorder_traversal(struct node* root){
    if (root != NULL){
      postorder_traversal(root->left);
      postorder_traversal(root->right);
      printf("%d ", root->data);
    }
  }
//Percurso de travessia em largura
void breadth_first_traversal(struct node* root){
  if(root == NULL){
    printf("A �rvore est� vazia.\n");
  }
  else{
    struct Queue* q = createQueue(); //cria uma fila vazia
    enqueue(q, root); //adiciona a raiz � fila
    while(!isEmpty(q)){ //enquanto a fila n�o estiver vazia
      struct node* current = q->front->data; //pega o primeiro elemento da fila
      printf("%d ", current->data); //imprime o dado do n� atual
      dequeue(q); //remove o primeiro elemento da fila
      if(current->left != NULL){ //se o n� atual tem filho � esquerda
        enqueue(q, current->left); //adiciona o filho � esquerda � fila
      }
      if(current->right != NULL){ //se o n� atual tem filho � direita
        enqueue(q, current->right); //adiciona o filho � direita � fila
      }
    }
  }
}

int main(){

  setlocale(LC_ALL, "Portuguese");
  int choice, x;
  printf("Digite o n�mero que servir� como root: \n");
  scanf("%d",&x);
  struct node* root = create_node(x);

  do{
    printf("\nEscolha uma op��o:\n\n1-Insert Data\n2-In Order Traversal\n3-Pre Order Traversal\n4-Post Order Traversal\n5-Lenght Traversal\n0-Sair\n\n");
    scanf("%d",&choice);
    
    switch(choice){
      case 1:
        printf("\nDigite um n�mero a ser inserido na �rvore: \n");
        scanf("%d",&x);
        insert(root, x);
      break;
      case 2:
        inorder_traversal(root);
      break;
      case 3:
        preorder_traversal(root);
      break;
      case 4:
        postorder_traversal(root);
      break;
      case 5:
        breadth_first_traversal(root);
      break;
    }
  }while(choice);

  
  return 0;
  
}


