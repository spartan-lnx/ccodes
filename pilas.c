#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int value;
  struct _node *next;
} Node;


Node* initNode(int value);
void push(Node* node, Node** head);
Node* pop(Node** head);
Node peek(Node* head);

int main(int argc, char** argv)
{
    Node* temp = NULL;
    Node* head = NULL;

    Node* a = initNode(20);
    Node* b = initNode(15);
    Node* c = initNode(5);
    Node* d = initNode(33);
    Node* e = initNode(45);
    
    push(a,&head);
    push(b,&head);
    push(c,&head);
    push(d,&head);
    push(e,&head);

    Node p = peek(head);

    printf("peek: %d | %p \n",p.value,p.next);

    while(head != NULL)
    {
        temp = pop(&head);
        printf("%d | %p\n",temp->value,temp);
        free(temp);
    }

   return 0;
}


Node* initNode(int value)
{
   Node* node = (Node*) malloc(sizeof(Node));
   
   if(node == NULL)
   {
       printf("Error al inicializar nodo\n");
       return NULL;
   }

   node->value = value;
   node->next = NULL;
   return node;
}


void push(Node* node, Node** head)
{
    if(*head == NULL)
    {
        *head = node;
        return;
    }

    node->next = *head;
    *head = node;
}

Node* pop(Node** head)
{
    if(*head == NULL)
    {
        printf("No hay nodos en la pila\n");
        return NULL;
    }
    Node* node = *head; 
    *head = (*head)->next;

    return node;
}

Node peek(Node* head)
{
    Node node = {.value = head->value, .next = head->next};

    return node;
}
