/* Joel Joseph,29
      Binary tree using array */
#include <stdio.h>
#include <stdlib.h>

const int size=100;
int binaryTree[100];

void initialise() 
{
	int i=0;
	for (i=0; i<size; i++)
		binaryTree[i] = -1;
}
void inorder(int root) 
{
	int left, right;
	if (root<size) 
	{
		if (binaryTree[root] != -1) 
		{
			left = root*2+1;
			right = root*2+2;
			if (left<size)
				if (binaryTree[left] != -1)
					inorder(left);
			printf(" %d", binaryTree[root]);
			if (right<size)
				if (binaryTree[right] != -1)
					inorder(right);
		}
	}
}

// searches for key
// returns its position if found
// returns -1 if not found
int search(int key) 
{
	int i=0;
	for (i=0; i<size; i++)
		if (binaryTree[i]==key) return i;
	return -1;
}
void insert(int key) 
{
	int index, data;
	char child;
	index = search(key);
	if (index == -1) 
	{
		if (binaryTree[0] == -1) 
		{
			printf("Enter data to be inserted : ");
			scanf("%d", &data);
			binaryTree[0] = data;
			printf("Successfully inserted\n");
			return;
		}
		printf("Key not found");
	} else 
	{
		printf("Enter data to be inserted : ");
		scanf("%d", &data);
		printf("Where do you want to enter the data (L/R): ");
		scanf(" %c", &child);
		if (child == 'l' || child == 'L')
			if (2*index+1<size) 
			{
				binaryTree[2*index+1] = data;
				printf("Successfully inserted\n");
			}
			else
				printf("Out of memory. Cannot insert\n");
		else
			if (2*index+2<size) 
			{
				binaryTree[2*index+2] = data;
				printf("Successfully inserted\n");
			}
			else
				printf("Out of memory. Cannot insert\n");
	}
}

int showMenu() 
{
	char choice;
	int key, index;
	do 
	{
		printf("\tBinary Tree\n");
		printf("1. Insert\n");
		printf("2. Search\n");
		printf("3. Delete\n");
		printf("4. Print\n");
		printf("5. Exit\n");
		printf("Enter your choice : ");
		scanf(" %c", &choice);
		switch (choice) 
		{
			case '1':
				printf("Enter data of the parent node : ");
				scanf("%d", &key);
				insert(key);
				break;
			case '2':
				printf("Enter data of the node to be searched : ");
				scanf("%d", &key);
				index = search(key);
				if (index==-1)
					printf("Element not found\n");
				else
					printf("Node found\n");
			case '3':
				break;
			case '4':
				inorder(0);
				break;
			case '5':
				break;
			default:
				printf("Invalid option\n");
				break;
		}
	} while(choice!='5');
}
int main() 
{
	initialise();
	showMenu();
}
