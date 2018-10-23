/* Joel Joseph
   S3 D 29
   Double Linked List */

#include <stdio.h>
#include <stdlib.h>
struct node
{

  int data;

  struct node* next;

  struct node* prev;

}*HEADER;

struct node* newNode()

{

  struct node* newptr = malloc(sizeof(struct node));

  if (newptr == NULL) {

    printf("Memory overflow\n");

   

    exit(0);

  }

  return (newptr);

}

int insertNodeFront (int data) 

{

  struct node *new = newNode();

  new->data = data;

  new->prev = HEADER;

  new->next = HEADER->next;

  HEADER->next = new;

  if (new->next != NULL)

    new->next->prev = new;

  return (0);

}

int insertNodeBefore(int data, int nextData)

{

  struct node *new = newNode(), *currentNode=HEADER;

  new->data = data;

  while (currentNode->next != NULL && currentNode->data != nextData) 

  {

    currentNode = currentNode->next;

  }

  if (currentNode->data == nextData)

  {

    new->next = currentNode;

    new->prev = currentNode->prev;

    currentNode->prev = new;

    if (new->next != NULL)

      new->prev->next = new;

  } else 

  {

    printf("Insertion failed. Element not found\n");

  }

  return (0);

}

int insertNodeAfter(int data, int prevData) 

{

  struct node *new = newNode(), *currentNode=HEADER->next;

  new->data = data;

  while (currentNode != NULL && currentNode->data != prevData) 

  {

    currentNode = currentNode->next;

  }

  if (currentNode->data != prevData) 

  {

    printf("Insertion failed. Element not found\n");

  } else {

    new->prev = currentNode;

    new->next = currentNode->next;

    currentNode->next = new;

    if (new->next != NULL)

    {

      new->next->prev = new;

    }

  }

  return (0);

}

int insertNodeBack (int data)

{

  struct node *new = newNode(), *currentNode=HEADER;

  while (currentNode->next != NULL)

  {

    currentNode = currentNode->next;

  }

  new->data = data;

  new->next = NULL;

  new->prev = currentNode;

  currentNode->next = new;

  return (0);

}

int deleteFirstNode ()

{

  struct node *currentNode = HEADER->next;

  if (HEADER->next == NULL)

  {

    printf("Empty linked list\n");

  } else {

    HEADER->next = HEADER->next->next;

    HEADER->next->prev = HEADER;

    free(currentNode);

  }

  return (0);

}

int deleteLastNode () 

{

  struct node *currentNode = HEADER;

  while (currentNode->next != NULL)

  {

    currentNode = currentNode->next;

  }

  if (currentNode == HEADER)

  {

    printf ("Empty linked list");

  } else {

    currentNode->prev->next = NULL;

    free(currentNode);

  }

  return (0);

}

int deleteNode(int data)

{

  struct node *currentNode = HEADER;

  while (currentNode->next != NULL && currentNode->data != data) 

  {

    currentNode = currentNode->next;

  }

  if (currentNode->data != data)

  {

    printf("Deletion failed. Node with matching data not found\n");

  } else {

    currentNode->prev->next = currentNode->next;

    if (currentNode->next != NULL)

    {

      currentNode->next->prev = currentNode->prev;

    }

    free(currentNode);

  }

  return (0);

}

int printAll() 

{

  struct node* currentNode = HEADER->next;

  printf("NULL<-HEADER<->");

  while (currentNode->next != NULL)

  {

    printf("%d<->", currentNode->data);

    currentNode = currentNode->next;

  }

  printf("%d->NULL\n", currentNode->data);

  return (0);

}

int showMenu(

) {

  char choice;

  int data, previousData, nextData;

  while (1) 

  {

    printf("\n\n\tDoubly Linked List\n");

    printf("1. Insert at Front\n");

    printf("2. Insert before\n");

    printf("3. Insert after\n");

    printf("4. Insert at End\n");

    printf("5. Print Linked List\n");

    printf("6. Delete first node\n");

    printf("7. Delete node\n");

    printf("8. Delete last node\n");

    printf("0. Exit\n");

    printf("Enter your choice : ");

    scanf(" %c", &choice);

    printf("\n");

    switch (choice) 

    {

      case '1':

        printf("Enter new data : ");

        scanf("%d", &data);

        insertNodeFront(data);

        break;

      case '2': 

        printf("Enter new data : ");

        scanf("%d", &data);

        printf("Enter data of the node before which new node is to be created : ");

        scanf("%d", &nextData);

        insertNodeBefore(data, nextData);

        break;

      case '3': 

        printf("Enter new data : ");

        scanf("%d", &data);

        printf("Enter data of the node after which new node is to be created : ");

        scanf("%d", &previousData);

        insertNodeAfter(data, previousData);

        break;

      case '4':

        printf("Enter new data : ");

        scanf("%d", &data);

        insertNodeBack(data);

        break;

      case '5':

        printAll();

        break;

      case '6':

        deleteFirstNode();

        break;

      case '7':

        printf("Enter data of the node to be deleted : ");

        scanf("%d", &data);

        deleteNode(data);

        break;

      case '8':

        deleteLastNode();

        break;

      case '0':

        exit(0);

        break;

      default:

         break;

    }

  }

  return (0);

}

int main() 

{

  HEADER = malloc(sizeof(struct node));

  HEADER->data = 0;

  HEADER->next = NULL;

  HEADER->prev = NULL;

  showMenu();

  return (0);

}