#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int value;
  struct _node *next;
} Node;


Node* initNode(int value);
void insertFirst(Node* node, Node** head);
void deleteFirst(Node** head);
void displayForward(Node* head);
Node* searchNode(int key, Node* head);
void deleteByKey(int key, Node** head); 

int main(int argc, char** argv)
{
    Node* temp = NULL;
    Node* head = NULL;

    Node* a = initNode(20);
    Node* b = initNode(15);
    Node* c = initNode(5);
    Node* d = initNode(33);
    Node* e = initNode(45);

    insertFirst(a,&head);
    insertFirst(b,&head);
    insertFirst(c,&head);
    insertFirst(d,&head);
    insertFirst(e,&head);

    displayForward(head);
    deleteFirst(&head);
    displayForward(head);
    searchNode(5,head);
    searchNode(1,head);
    deleteByKey(33,&head);
    deleteByKey(20,&head);
    displayForward(head);

    free(b);
    free(c);
    
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

void insertFirst(Node* node, Node** head)
{
    if(*head == NULL)
    {
        *head = node;
        printf("Insertando enfrente a %d en %p\n",node->value,node);
        return;
    }

    node->next = *head;
    *head = node;
    printf("Insertando enfrente a %d en %p\n",node->value,node);
}

void deleteFirst(Node** head)
{
    Node* temp = *head;

    if(*head == NULL)
    {
        printf("No hay nodos en la lista\n");
        return;
    }

    *head = (*head)->next;

    printf("eliminando a %d en %p\n",temp->value,temp);
    free(temp);
}


void displayForward(Node* head)
{
    Node* temp = head;
    printf("[");
    while(temp != NULL)
    {
        printf("%d%s",temp->value,(temp->next != NULL)?", ":"");
        temp = temp->next;
    }
    printf("]\n");
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

void deleteByKey(int key, Node** head)
{
    Node* tempprev = *head;
    Node* temp = tempprev->next;

    // Caso especial: Al inicio del listado
    if((*head)->value == key)
    {
        deleteFirst(head);
        return;     
    }

    while(temp != NULL)
    {
        if(temp->value == key)
        {
            printf("Nodo con clave %d encontrado en %p!\n",temp->value,temp);
            tempprev->next = temp->next;
            printf("Eliminando a %d en direccion %p\n",temp->value,temp);
            free(temp);
            return;
        }
        tempprev = temp;
        temp = temp->next;
    }

    printf("Clave %d inexistente en la lista enlazada!\n");
}
