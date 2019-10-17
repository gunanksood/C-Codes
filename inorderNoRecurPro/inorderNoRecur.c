#include <stdio.h>
#include <stdarg.h>

#include "tree.h"
#include "stack.h"

void printstack(node *stack)
{
  printf("stack: ");
  while (!isempty(stack))
  {
    printf("%p ", stack->top->data);
  }
  printf("\n");
}

void inorder(tree *root)
{
  node *stack = NULL;
  while (1)
  {
    if (root)
    {
      push(root, &stack);
      root = root->left;
    }
    else
    {
      if (!isempty(stack))
      {
        root = stack->top;
        pop(&stack);
        printf("%d ", root->data);
        root = root->right;
      }
      else
      {
        break;
      }
    }
  }
}

int main()
{
  // FILE *output = freopen("out.txt", "w", stdout);
  // FILE *input = freopen("in.txt", "r", stdin);

  tree *root = NULL;

  int n, val;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &val);
    root = insert(root, val);
  }

  // inorderFake(root);
  inorder(root);

  // fclose(output);
  // fclose(input);
  return 0;
}