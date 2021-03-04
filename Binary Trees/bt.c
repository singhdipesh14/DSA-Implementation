#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  char item;
  struct node *right;
  struct node *left;
} * Tree;

void insert(Tree *root, char item, char *place)
{
  Tree n = (Tree)malloc(sizeof(struct node));
  n->item = item;
  n->left = NULL;
  n->right = NULL;
  if (*root == NULL)
  {
    *root = n;
    return;
  }
  Tree prev = NULL;
  Tree cur = *root;
  int i;
  for (i = 0; place[i] != '\0'; i++)
  {
    prev = cur;
    if (*(place + i) == 'L' || *(place + i) == 'l')
    {
      cur = cur->left;
    }
    else
    {
      cur = cur->right;
    }
  }
  i--;
  if (*(place + i) == 'L' || *(place + i) == 'l')
    prev->left = n;
  else
    prev->right = n;
}

void inorder(Tree root)
{
  if (root)
  {
    inorder(root->left);
    printf("%c", root->item);
    inorder(root->right);
  }
}

void preorder(Tree root)
{
  if (root)
  {
    printf("%c", root->item);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(Tree root)
{
  if (root)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->item);
  }
}

int main()
{
  Tree root = NULL;
  int choice = 0;
  char *s;
  char ele;
  while (choice < 5)
  {
    printf("1: Insert\n2: Inorder\n3: Preorder\n4: Postorder\n5: Exit\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the element to be entered : ");
      scanf(" %c", &ele);
      printf("Enter the path : ");
      s = (char *)calloc(20, sizeof(char));
      scanf(" %s", s);
      insert(&root, ele, s);
      break;

    case 2:
      printf("\n");
      inorder(root);
      printf("\n");
      break;

    case 3:
      printf("\n");
      preorder(root);
      printf("\n");
      break;
    case 4:
      printf("\n");
      postorder(root);
      printf("\n");
      break;
    default:
      continue;
    }
  }
  return 0;
}