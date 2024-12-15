



#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*this is initializing a node*/
struct Node
{
  int data;
  struct Node *next;
};

struct List
{
  struct Node *head;
  int length;
};
/*this is the function used to create the list*/
struct List *createList()
{
  struct List *list = (struct List *)malloc(sizeof(struct List));
  list->head = NULL;
  list->length = 0;
  return list;
}
/*pushing function*/
void push(struct List *list, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;
  list->length++;
}

void insertBottom(struct List *list, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  struct Node *current = list->head;
  newNode->data = data;
  newNode->next = NULL;
  if (list->head == NULL)
  {
    list->head = newNode;
    list->length++;
    return;
  }
  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = newNode;
  list->length++;
}

void insertSorted(struct List *list, struct Node *toAdd)
{
  struct Node *current = list->head;
  if (list->head == NULL)
  {
    list->head = toAdd;
    list->length++;
    return;
  }
  if (list->head->data > toAdd->data)
  {
    toAdd->next = list->head;
    list->head = toAdd;
    list->length++;
    return;
  }
  while (current->next != NULL && current->next->data < toAdd->data)
  {
    current = current->next;
  }
  toAdd->next = current->next;
  current->next = toAdd;
  list->length++;
}

void printList(struct List *list)
{
  struct Node *n = list->head;
  while (n != NULL)
  {
    printf("data: %d \n", n->data);
    n = n->next;
  }
}

struct Node *createNode(int data)
{
  struct Node *Node = (struct Node *)malloc(sizeof(struct Node));
  Node->data = data;
  Node->next = NULL;
  return Node;
}
/*pop function*/
struct Node *pop(struct List *list)
{
  struct Node *temp = list->head;
  if (list->head == NULL)
  {
    return NULL;
  }
  list->head = list->head->next;
  list->length--;
  return temp;
}
/*pop from Back function*/
int popFromBack(struct List *list)
{
  struct Node *current = list->head;
  int data;

  if (list->head == NULL)
  {
    return -1;
  }
  if (list->head->next == NULL)
  {
    int data = list->head->data;
    free(list->head);
    list->head = NULL;
    list->length--;
    return data;
  }
  while (current->next->next != NULL)
  {
    current = current->next;
  }
  data = current->next->data;
  free(current->next);
  current->next = NULL;
  list->length--;
  return data;
}

int getFromBack(struct List *list)
{
  struct Node *current = list->head;
  if (list->head == NULL)
  {
    return 0;
  }
  while (current->next->next != NULL)
  {
    current = current->next;
  }
  return current->data;
}

int isOperand(char c)
{
  if(c == '+' || c == '-' || c == '*' || c == '/')
  {
    return 1;
  }
  return 0;
}

int evaluate(char c, int a, int b){
  switch (c)
  {
    case '+':
      return b + a;
    case '-':
      return b - a;
    case '*':
      return b * a;
    case '/':
      return b / a;
    default:
      printf("Invalid operator");
      return 0;
  }
}

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    printf("Usage: ./q2 \"expression\"\n");
    return 0;
  }

  char *postfix = argv[1];
  struct List *list = createList();

  int i;
  for(i = 0; i < strlen(postfix); i++){
    if(isOperand(postfix[i]) == 1){
      int a = popFromBack(list);
      int b = popFromBack(list);
      int result = evaluate(postfix[i], a, b);
      insertBottom(list, result);
      
      
    }else{
      insertBottom(list, postfix[i] - '0');
      
    
    }
  }
  printf("Result: %d \n", list->head->data);
  return 0;
}
