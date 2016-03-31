/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
int linkedListMedian(struct node *head) {
	struct node *temp;
	if (head == NULL)
		return -1;
	int i = 0, res, mid;
	for (temp = head; temp != NULL; temp = temp->next)
	{
		i++;
	}
	mid = i / 2;
	if (i % 2 == 0)
	{
		temp = head;
		for (i = 0; i<mid; i++)
		{
			res = (temp->num + temp->next->num) / 2;;
			temp = temp->next;
		}
	}
	else
	{
		temp = head;
		for (i = 0; i<mid + 1; i++)
		{
			res = temp->num;
			temp = temp->next;
		}
	}

//	printf(" res is %d", res);
	return res;
}