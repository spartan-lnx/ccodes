#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int value;
  struct _node *next;
  struct _node *prev;
} Node;


Node* initNode(int value);
void displayForward(Node* head);
void displayBackward(Node* tail);
Node* searchNode(int key, Node* head);

void insertFirst(Node* node, Node** head, Node** tail);
void insertLast(Node* node, Node** head, Node** tail);
void insertAfter(Node* node, Node** after, Node** head, Node** tail);
void deleteFirst(Node** head, Node** tail);
void deleteLast(Node** head, Node** tail);
void deleteByKey(int key, Node** head, Node** tail); 

int main(int argc, char** argv)
{
    Node* temp = NULL;
    Node* temp2 = NULL;
    Node* head = NULL;
    Node* tail = NULL;
    int i,num;
    
    for(i=0;i<10;i++)
    {
        temp = initNode(i);
        insertLast(temp,&head,&tail);
    }

    displayForward(head);
    displayBackward(tail);

    searchNode(9,head);
    searchNode(2,head);
    searchNode(33,head);
    temp = initNode(-1);
    insertFirst(temp,&head,&tail);
    temp = initNode(33);
    temp2 = searchNode(3,head);
    insertAfter(temp,&temp2,&head,&tail);
    displayForward(head);
    deleteFirst(&head,&tail);
    deleteLast(&head,&tail);
    deleteByKey(33,&head,&tail);
    displayForward(head);

    while(head != NULL)
    {
        deleteFirst(&head,&tail);
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
   node->prev = NULL;
   return node;
}

void displayForward(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        printf("[%d]",temp->value);
        temp = temp->next;
    }
    printf("\n");   
}

void displayBackward(Node* tail)
{
    Node* temp = tail;
    while(temp != NULL)
    {
        printf("[%d]",temp->value);
        temp = temp->prev;
    }
    printf("\n");   
}

Node* searchNode(int key, Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->value == key)
        {
            printf("Nodo con clave %d encontrado en %p!\n",temp->value,temp);
            return temp;
        }
        temp = temp->next;
    }
    printf("Clave %d inexistente en la lista enlazada!\n");
    return NULL;
}

void insertFirst(Node* node, Node** head, Node** tail)
{
    if(*head == NULL)
    {
        *head = node;
        *tail = node;
        printf("Insertando al inicio a %d en %p\n",node->value,node);
        return;
    }

    node->next = *head;
    (*head)->prev = node;
    *head = node;
    printf("Insertando al inicio a %d en %p\n",node->value,node);
}

void insertLast(Node* node, Node** head, Node** tail)
{
    if(*head == NULL)
    {
        *head = node;
        *tail = node;
        printf("Insertando al final a %d en %p\n",node->value,node);
        return;
    }

    (*tail)->next = node;
    node->prev = *tail;
    *tail = node;
    printf("Insertando al final a %d en %p\n",node->value,node);
}

void insertAfter(Node* node, Node** after, Node** head, Node** tail)
{
    Node* temp = NULL;

    // Caso especial: Al final de la lista
    if((*after) == (*tail))
    {
        printf("Insertando a %d enfrente de %d en %p\n",node->value,(*after)->value,node);
        insertLast(node, head, tail);
        return;
    }

    printf("Insertando a %d enfrente de %d en %p\n",node->value,(*after)->value,node);
    temp = (*after)->next;
    temp->prev = node;
    (*after)->next = node;
    node->prev = *after;
    node->next = temp;
}

void deleteFirst(Node** head, Node** tail)
{
    Node* temp = *head;

    if(*head == NULL)
    {
        printf("No hay nodos en la lista\n");
        return;
    }

    if(*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
        printf("Eliminando a %d al inicio\n",temp->value);
        free(temp);
        return;
    }
    
    printf("Eliminando a %d al inicio\n",(*head)->value);
    *head = (*head)->next;
    (*head)->prev = NULL;

    free(temp);
}



void deleteLast(Node** head, Node** tail)
{
    Node* temp = *tail;

    if(*head == NULL)
    {
        printf("No hay nodos en la lista\n");
        return;
    }

    if(*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
        printf("Eliminando a %d al final\n",temp->value);
        free(temp);
        return;
    }
    
    printf("Eliminando a %d al final\n",(*tail)->value);
    *tail = (*tail)->prev;
    (*tail)->next = NULL;

    free(temp);
}


void deleteByKey(int key, Node** head, Node** tail)
{
    Node* temp = NULL;

    // Caso especial: Al inicio del listado
    if((*head)->value == key)
    {
        deleteFirst(head, tail);
        return;     
    }

    // Caso especial: Al final del listado
    if((*tail)->value == key)
    {
        deleteLast(head, tail);
        return;     
    }

    temp = searchNode(key,*head);

    if(temp == NULL)
    {
        printf("Nodo no encontrado en la lista\n");
        return;
    }

    printf("Eliminando a %d\n",temp->value);
    (temp->prev)->next = temp->next;
    (temp->next)->prev = temp->prev;

    free(temp);
}
