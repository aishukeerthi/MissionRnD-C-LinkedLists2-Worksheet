/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
}*head, *temp, *current, *new_node;
struct node *create_node(int data)
{
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->num = data;
	new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
		current = new_node;
	}
	else
	{
		current->next = new_node;
		current = new_node;
	}
	return head;
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL && head2 != NULL)
		return head2;
	else if (head1 != NULL && head2 == NULL)
		return head1;

	int i = 0, j = 0, k = 0, Alen, Blen;
	int A[10], B[10];
	head = NULL;
	for (temp = head1; temp != NULL; temp = temp->next)
	{
		A[i++] = temp->num;
	}
	for (temp = head2; temp != NULL; temp = temp->next)
	{
		B[j++] = temp->num;
	}
	Alen = i;
	Blen = j;
	int *C = (int *)malloc(sizeof(int)*(i + j));
	i = 0, j = 0;
	while (i<Alen && j<Blen)
	{
		if (A[i]<B[j])
		{
			C[k++] = A[i++];
		}
		else
		{
			C[k++] = B[j++];
		}
	}
	while (i<Alen)
	{
		C[k] = A[i++];
		k++;
	}
	while (j<Blen)
	{
		C[k] = B[j++];
		k++;
	}
	struct node *result = (struct node*)malloc(sizeof(struct node)*(Alen + Blen));
	for (i = 0; i<k; i++)
	{
		result = create_node(C[i]);
	}
	return result;
}
