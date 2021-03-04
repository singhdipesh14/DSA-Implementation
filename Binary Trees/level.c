#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  char item;
  struct node *right;
  struct node *left;
} * Tree;

typedef struct Queue
{
  int front, rear;
  Tree array[50];
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
  if (st.rear == 49)
  {
    return 1;
  }
  return 0;
}

int isEmpty(TreeStack st)
{
  if (st.rear == -1)
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
  if (st->front == -1)
  {
    st->front++;
  }
  st->array[(++st->rear)] = item;
}

Tree pop(TreeStack *st)
{
  if (isEmpty(*st))
  {
    return NULL;
  }

  Tree temp = st->array[(st->front)++];
  if (st->front > st->rear)
  {
    st->front = -1;
    st->rear = -1;
  }
  return temp;
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

void levelorder(Tree root)
{
  TreeStack q;
  q.front = q.rear = -1;
  if (!root)
  {
    return;
  }
  push(&q, root);
  while (1)
  {
    root = pop(&q);
    if (!root)
    {
      break;
    }
    printf("%c", root->item);
    if (root->left)
    {
      push(&q, root->left);
    }
    if (root->right)
    {
      push(&q, root->right);
    }
  }
}

int main()
{
  Tree root = NULL;
  int choice = 0;
  char *s;
  char ele;
  while (choice < 6)
  {
    printf("1: Insert\n2: Inorder\n3: Preorder\n4: Postorder\n5: Levelorder\n6: Exit\nEnter your choice : ");
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
    case 5:
      printf("\n");
      levelorder(root);
      printf("\n");
      break;
    default:
      continue;
    }
  }
  return 0;
}