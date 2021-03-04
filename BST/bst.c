#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} * Tree;

Tree minValue(Tree root)
{
  while (root && root->left)
  {
    root = root->left;
  }
  return root;
}

void insert(Tree *root, int data)
{
  Tree n = (Tree)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  if (*root == NULL)
  {
    *root = n;
    return;
  }
  Tree cur = *root, prev = NULL;
  while (cur)
  {
    if (data == cur->data)
    {
      free(n);
      return;
    }
    if (data > cur->data)
    {
      prev = cur;
      cur = cur->right;
    }
    else
    {
      prev = cur;
      cur = cur->left;
    }
  }
  if (data > prev->data)
  {
    prev->right = n;
  }
  else
    prev->left = n;
}

Tree delete (Tree root, int data)
{
  if (root == NULL)
  {
    return root;
  }
  else if ((root)->data < data)
  {
    (root)->right = delete ((root)->right, data);
  }
  else if ((root)->data > data)
  {
    (root)->left = delete ((root)->left, data);
  }
  else
  {
    if ((root)->left == NULL)
    {
      Tree temp = (root)->right;
      free(root);
      return temp;
    }
    else if ((root)->right == NULL)
    {
      Tree temp = (root)->left;
      free(root);
      return temp;
    }
    Tree mn = minValue((root)->right);
    (root)->data = mn->data;
    (root)->right = delete ((root)->right, mn->data);
  }
  return root;
}

void inorder(Tree root)
{
  if (root)
  {
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
  }
}

int main()
{
  Tree root = NULL;
  int choice = 0;
  char *s;
  int ele;
  while (choice < 4)
  {
    printf("1: Insert\n2: Inorder\n3: Delete\n4: Exit\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the element to be entered : ");
      scanf("%d", &ele);
      insert(&root, ele);
      break;

    case 2:
      printf("\n");
      inorder(root);
      printf("\n");
      break;
    case 3:
      printf("\n");
      printf("Enter the element to be deleted : ");
      scanf("%d", &ele);
      root = delete (root, ele);
      break;
    default:
      continue;
    }
  }
  return 0;
}