#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int value;
  struct _node *next;
} Node;


Node* initNode(int value);
void enqueue(Node* node, Node** head, Node** tail);
Node* dequeue(Node** head);
int isEmpty(Node* head, Node* tail);
Node peek(Node* head);

int main(int argc, char** argv)
{
    Node* temp = NULL;
    Node* head = NULL;
    Node* tail = NULL;

    Node* a = initNode(20);
    Node* b = initNode(15);
    Node* c = initNode(5);
    Node* d = initNode(33);
    Node* e = initNode(45);
    
    enqueue(a,&head,&tail);
    enqueue(b,&head,&tail);
    enqueue(c,&head,&tail);
    enqueue(d,&head,&tail);
    enqueue(e,&head,&tail);

    Node p = peek(head);

    printf("peek: %d | %p \n",p.value,p.next);

    //while(head != NULL)
    while(!isEmpty(head,tail))
    {
        temp = dequeue(&head);
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


void enqueue(Node* node, Node** head, Node** tail)
{
    if(isEmpty(*head,*tail))
    {
        *head = node;
        *tail = node;
        return;
    }
    
    (*tail)->next = node;
    *tail = node;
}

Node* dequeue(Node** head)
{
    if(*head == NULL)
    {
        printf("No hay nodos en la cola\n");
        return NULL;
    }
    Node* node = *head; 
    *head = (*head)->next;

    return node;
}

int isEmpty(Node* head, Node* tail)
{
    return (head == NULL && tail == NULL);
}

Node peek(Node* head)
{
    Node node = {.value = head->value, .next = head->next};

    return node;
}
