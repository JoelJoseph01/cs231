/* Joel Joseph
 S3 D,29
 Binary tree using linked list */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *right;
	struct node *left;
}*ROOT;
int deleteAll(struct node *root) {
  if (root->left != NULL) {
    deleteAll(root->left);
  }
  if (root->right != NULL) {
    deleteAll(root->right);
  }
  free(root);
}
struct node *newNode() {
	struct node *newptr = malloc(sizeof(struct node));
	if (newptr == NULL) {
		printf("Memory overflow");
		deleteAll(ROOT);
		exit(0);
	}
	return (newptr);
}
void inorder(struct node *root) {
  if (root->left != NULL) {
    inorder(root->left);
  }
  printf(" %d", root->data);
  if (root->right != NULL) {
    inorder(root->right);
  }
}
struct node* getParent(struct node *root, struct node *child) {
  struct node *parent = NULL;
  if (root != NULL) {
    if (root->right == child || root->left == child) parent = root;
    if (parent == NULL)
      parent = getParent(root->left, child);
    if (parent == NULL)
      parent = getParent(root->right, child);
  }
  return parent;
}
struct node* search(struct node *root, int key) {
  struct node *index;
  if (root->data == key) return root;
  if (root->left != NULL) {
    index = search(root->left, key);
    if (index != NULL) {
      return index;
    }
  }
  if (root->right != NULL) {
    index = search(root->right, key);
    if (index != NULL) {
      return index;
    }
  }
  return NULL;
}
struct node* createNode(int data) {
  struct node *newNode = malloc(sizeof(struct node));
  if (newNode == NULL) {
    printf("Memory overflow");
    deleteAll(ROOT);
    exit(0);
  }
  newNode->right = NULL;
  newNode->left = NULL;
  newNode->data = data;
  return newNode;
}
void insert() {
  int data, key;
  struct node *parent, *newNode;
  char choice;
  if (ROOT == NULL) {
    printf("Enter data to be inserted : ");
    scanf("%d", &data);
    ROOT = createNode(data);
    printf("Successfully inserted\n");
  } else {
    parent=search(ROOT, key);
    printf("Enter data of the parent node : ");
    scanf("%d", &key);
    parent = search(ROOT, key);
    if (parent == NULL) {
      printf("Parent node not found. Deletion failed\n");
    } else {
      printf("Enter data to be inserted : ");
      scanf("%d", &data);
      printf("Enter which child to be inserted at (L/R) : ");
      scanf(" %c", &choice);
      switch(choice) {
        case 'l':
        case 'L':
          newNode = createNode(data);
          parent->left = newNode;
          printf("Succesfully inserted\n");
          break;
        case 'r':
        case 'R':
          newNode = createNode(data);
          parent->right = newNode;
          printf("Succesfully inserted\n");
          break;
        default:
          printf("Invalid choice\n");
      }
    }
  }
}
struct node* deepRight(struct node *root) {
  if (root->right != NULL) {
    return deepRight(root->right);
  } else if (root->left != NULL) {
    return deepRight(root->left);
  } else {
    return root;
  }
}
void delete() {
  int key;
  struct node *toMove, *parent, *toDelete;
  printf("Enter data of the node to be deleted : ");
  scanf("%d", &key);
  toDelete = search(ROOT, key);
  if (toDelete == NULL) {
    printf("Node not found\n");
  } else {
    if (toDelete->right == NULL && toDelete->left == NULL) {
      parent = getParent(ROOT, toDelete);
      if (parent->right == toDelete)
        parent->right = NULL;
      else if (parent->left == toDelete)
        parent->left = NULL;
      free(toDelete);
    } else {
      toMove = deepRight(ROOT);
      toDelete->data = toMove->data;
      parent = getParent(ROOT, toMove);
      if (parent->right == toMove)
        parent->right = NULL;
      else if (parent->left == toMove)
        parent->left = NULL;
      free(toMove);
    }
  }
}
int showMenu() {
	char choice;
	int key, index;
  struct node *temp;
	do {
		printf("\n\tBinary Tree\n");
		printf("1. Insert\n");
		printf("2. Search\n");
		printf("3. Delete\n");
		printf("4. Print\n");
		printf("5. Exit\n");
		printf("Enter your choice : ");
		scanf(" %c", &choice);
		switch (choice) {
			case '1':
				insert();
				break;
			case '2':
				printf("Enter data to be searched : ");
				scanf("%d", &key);
				temp = search(ROOT, key);
				if (temp == NULL)
					printf("Element not found\n");
				else
					printf("Node found\n");
				break;
			case '3':
				delete();
				break;
			case '4':
				inorder(ROOT);
				break;
			case '5':
        deleteAll(ROOT);
				break;
			default:
				printf("Invalid option\n");
				break;
		}
	} while(choice!='5');
}
int main() {
  ROOT=NULL;
	showMenu();
}
