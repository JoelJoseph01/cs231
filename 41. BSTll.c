/* Joel Joseph
   S3 D 29
   BST using LL
   
   
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
  struct node *parent=ROOT, *newNode;
  printf("Enter data to be inserted : ");
  scanf("%d", &data);
  if (ROOT==NULL) {
    ROOT = createNode(data);
    printf("Succesfully inserted\n");
  } else {
    parent = ROOT;
    while (parent != NULL) {
      if (data>parent->data) {
        if (parent->right == NULL) {
          newNode = createNode(data);
          parent->right = newNode;
          printf("Successfully inserted\n");
          break;
        } else {
          parent = parent->right;
        }
      } else {
        if (parent->left == NULL) {
          newNode = createNode(data);
          parent->left = newNode;
          printf("Successfully inserted\n");
          break;
        } else {
          parent = parent->left;
        }
      }
    }
  }
}
struct node* successor(struct node *root) {
  struct node *i;
  i = root->right;
  while (i->left != NULL) {
    i=i->left;
  }
  return i;
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
void delete() {
  int key;
  struct node *toDelete, *parent, *succ;
  printf("Enter data of the node to be deleted : ");
  scanf("%d", &key);
  toDelete = search(ROOT, key);
  if (toDelete == NULL) {
    printf("Node not found\n");
  } else {
    if (toDelete->right == NULL && toDelete->left == NULL) {
      parent = getParent(ROOT, toDelete);
	  if (parent!=NULL) {
		  if (parent->right == toDelete)
			parent->right = NULL;
		  else if (parent->left == toDelete)
			parent->left = NULL;
	  }
      free(toDelete);
	  toDelete = NULL;
      printf("Successfully deleted\n");
    } else if (toDelete->right != NULL && toDelete->left != NULL) {
      succ = successor(toDelete);
      toDelete->data = succ->data;
      parent = getParent(ROOT, succ);
	  if (parent != NULL) {
		  if (parent->right == succ)
			parent->right = NULL;
		  else if (parent->left == succ)
			parent->left = NULL;
	  }
      free(succ);
	  succ == NULL;
      printf("Successfully deleted\n");
    } else {
      parent = getParent(ROOT, toDelete);
      if (parent->right == toDelete) {
        if (toDelete->right != NULL) {
          parent->right = toDelete->right;
        }
        if (toDelete->left != NULL) {
          parent->right = toDelete->left;
        }
      } else {
        if (toDelete->right != NULL) {
          parent->left = toDelete->right;
        }
        if (toDelete->left != NULL) {
          parent->left = toDelete->left;
        }
      }
      printf("Successfully deleted\n");
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
