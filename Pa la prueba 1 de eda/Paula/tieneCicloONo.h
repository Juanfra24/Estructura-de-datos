
typedef struct node{
    int data;
    struct node *next;
}node;

int tieneCicloONo(node* head)
{
  if (head == NULL)
    return 0;

  node* temp1 = head;
  node* temp2 = head;

  while (temp1->next != NULL && temp1->next->next != NULL)
  {
    temp2 = temp2->next;
    temp1 = temp1->next->next;

    if (temp2 == temp1)
      return 1;
  }

  return 0;
}