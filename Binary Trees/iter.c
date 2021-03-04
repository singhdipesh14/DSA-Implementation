#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  char item;
  struct node *right;
  struct node *left;
} * Tree;

typedef struct Stack
{
  int top;
  Tree array[30];
} TreeStack;

Tree insert()
{
  printf("1 to enter, 0 to abort : ");
  int ele;
  char c;
  scanf("%d", &ele);
  Tree n = NULL;
  if (ele)
  {
    n = (Tree)malloc(sizeof(struct node));
    printf("Enter the element : \n");
    scanf(" %c", &c);
    n->item = c;
    printf("Enter the left child of %c\n", c);
    n->left = insert();
    printf("Enter the right child of %c\n", c);
    n->right = insert();
  }
  return n;
}

int isFull(TreeStack st)
{
  if (st.top == 29)
  {
    return 1;
  }
  return 0;
}

int isEmpty(TreeStack st)
{
  if (st.top == -1)
  {
    return 1;
  }
  return 0;
}

void push(TreeStack *st, Tree item)
{
  if (isFull(*st))
  {
    return;
  }
  st->array[(++st->top)] = item;
}

Tree pop(TreeStack *st)
{
  if (isEmpty(*st))
  {
    return NULL;
  }
  return st->array[(st->top)--];
}

void inorder(Tree root)
{
  Tree cur = root;
  TreeStack st;
  st.top = -1;
  while (1)
  {
    for (; cur; cur = cur->left)
    {
      push(&st, cur);
    }
    cur = pop(&st);
    if (cur == NULL)
    {
      break;
    }
    printf("%c", cur->item);
    cur = cur->right;
  }
}

void preorder(Tree root)
{
  Tree cur = root;
  TreeStack st;
  st.top = -1;
  while (1)
  {
    for (; cur; cur = cur->left)
    {
      printf("%c", cur->item);
      push(&st, cur);
    }
    cur = pop(&st);
    if (cur == NULL)
    {
      break;
    }
    cur = cur->right;
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
      root = insert();
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