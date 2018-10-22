#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
}*HEADER;
int deleteAll() 
{
	struct node *ptr = HEADER, *prevPtr;
	while (ptr != NULL) 
	{
		prevPtr = ptr;
		ptr = ptr->next;
		free(prevPtr);
	}
	return (0);
}
struct node *newNode()
 {
	struct node *newptr = malloc(sizeof(struct node));
	if (newptr == NULL)
	{
		printf("Memory overflow");
		deleteAll();
		exit(0);
	}
	return (newptr);
}
int deleteNode(int data) 
{
	struct node *currentNode = HEADER, *previousNode;
	while(currentNode->next != NULL && currentNode->data != data) 
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode->data != data)		
	{
		printf("Node not found.\nDeletion failed\n");
	} else 
	{
		previousNode->next = currentNode->next;
		free(currentNode);
	}
	return (0);
}
int deleteFirstNode() 
{
	struct node *currentNode = HEADER->next;
	if (currentNode == NULL)
	{
		printf("Empty linked list.\nDeletion failed.\n");
	} else 
	{
		HEADER->next = currentNode->next;
		free(currentNode);
	}
	return (0);
}
int deleteLastNode() 
{
	struct node *currentNode = HEADER, *previousNode;
	if (currentNode == NULL) 
	{
		printf("Empty linked list.\nDeletion failed.\n");
	} else 
	{
		while (currentNode->next != NULL)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		previousNode->next = NULL;
		free (currentNode);
	}
	return (0);
}
int insertNodeAfter(int data, int previousData) 
{
	struct node *newptr = newNode(), *currentNode = HEADER;
	while (currentNode->data != previousData && currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	if (currentNode->data != previousData)
	{
		printf("Node not found.\nInsertion Failed\n");
	} else 
	{
		newptr->next = currentNode->next;
		newptr->data = data;
		currentNode->next = newptr;
	}
	return (0);
}
int insertNodeBefore(int data, int nextData) 
{
	struct node *newptr = newNode(), *currentNode = HEADER, *previousNode;
	while (currentNode->data != nextData && currentNode->next !=NULL)
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode->data != nextData) 
	{
		printf("Node not found.\nInsertion Failed\n");
	} else 
	{
		newptr->next = previousNode->next;
		newptr->data = data;
		previousNode->next = newptr;
	}
	return (0);
}
int insertNodeFront(int data) 
{
	struct node *newptr = newNode();
	newptr->next = HEADER->next;
	newptr->data = data;
	HEADER->next = newptr;
	return (0);
}
int insertNodeEnd(int data) 
{
	struct node *newptr = newNode(), *currentNode = HEADER;

	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}

	newptr->next = currentNode->next;
	newptr->data = data;
	currentNode->next = newptr;
	return (0);
}

int printLinkedList() 
{
	struct node *currentNode = HEADER->next;
	printf("\nLinked List\nHEADER->");
	while (currentNode != NULL)
	{
		printf("%d->", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("NULL\n");
	return (0);
}

int showMenu() 
{
	char choice='1';
	int data, previousData, nextData;
	while(choice != '0') 
	
	{
		printf("\n\tLINKED LIST\n");
		printf("1. Insert at Front\n");
		printf("2. Insert before\n");
		printf("3. Insert after\n");
		printf("4. Insert at End\n");
		printf("5. Print Linked List\n");
		printf("6. Delete first node\n");
		printf("7. Delete last node\n");
		printf("8. Delete node\n");
		printf("9. Delete all\n");
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
				printf("Enter data before which new node is to be created : ");
				scanf("%d", &nextData);
				printf("Enter new data : ");
				scanf("%d", &data);
				insertNodeBefore(data, nextData);
				break;
			case '3':
				printf("Enter data after which new node is to be created : ");
				scanf("%d", &previousData);
				printf("Enter new data : ");
				scanf("%d", &data);
				insertNodeAfter(data, previousData);
				break;
			case '4':
				printf("Enter new data : ");
				scanf("%d", &data);
				insertNodeEnd(data);
				break;
			case '5':
				printLinkedList();
				break;
			case '6':
				deleteFirstNode();
				break;
			case '7':
				deleteLastNode();
				break;
			case '8':
				printf("Enter data to be deleted : ");
				scanf("%d", &data);
				deleteNode(data);
				break;
			case '9':
				deleteAll();
				break;
			case '0':
				deleteAll();
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
	showMenu();
	deleteAll();
	
	return (0);
}