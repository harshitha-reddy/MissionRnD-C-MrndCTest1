/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
void addNodeToList(struct node **finalLinkedList, struct node *nodeToBeAdded);
void CreateCircularLinkedList(struct node **finalLinkedList);
int addRemainingNodes(struct node **finalLinkedList, struct node *head1, struct node *head2);


void addNodeToList(struct node **finalLinkedList, struct node *nodeToBeAdded)
{
	struct node *recurser;
	if (*finalLinkedList == NULL)
	{
		*finalLinkedList = nodeToBeAdded;
	}
	else
	{
		recurser = *finalLinkedList;
		while (recurser->next != NULL)
			recurser = recurser->next;
		recurser->next = nodeToBeAdded;
	}
}
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (head1 == NULL || head2 == NULL)
		return -1;
	struct node *finallinkedlist = NULL;
	struct node *head1_temp, *head2_temp, *recurser;
	int length = 0;
	while (((((*head1)->data) < ((*head1)->next->data))) || ((((*head2)->data) < ((*head2)->next->data)))) 
	{
		if ((*head1)->data < ((*head2)->data))
		{
			printf("adding %d to the final list\n", (*head1)->data);
			head1_temp = (*head1)->next;
			(*head1)->next = NULL;
			addNodeToList(&finallinkedlist, *head1);
			*head1 = head1_temp; 


		}
		else
		{
			printf("adding %d to the final list\n", (*head2)->data);
			head2_temp = (*head2)->next;
			(*head2)->next = NULL;
			addNodeToList(&finallinkedlist, *head2);
			*head2 = head2_temp;
		}
		length++;
	}
	if (head1 != NULL && head2 != NULL)
		length += addRemainingNodes(&finallinkedlist, *head1, *head2);
	CreateCircularLinkedList(&finallinkedlist);
	*head1 = finallinkedlist;
	//printf("%d is the length\n", length);

	return length;
}
void CreateCircularLinkedList(struct node **finalLinkedList)
{
	struct node *recurser;
	if (*finalLinkedList == NULL)
	{
		return;
	}
	else
	{
		recurser = *finalLinkedList;
		while (recurser->next != NULL)
			recurser = recurser->next;
		recurser->next = *finalLinkedList;
	}

}
int addRemainingNodes(struct node **finalLinkedList, struct node *head1, struct node *head2)
{
	int length = 0;
	if (head1 != NULL&&head2 == NULL)
	{
		head1->next = NULL;
		addNodeToList(finalLinkedList, head1);
		length++;
	}
	else if (head2 != NULL&&head1 == NULL)
	{
		head2->next = NULL;
		addNodeToList(finalLinkedList, head2);
		length++;
	}
	else
	{
		if (head1->data<head2->data){
			head1->next = NULL;
			addNodeToList(finalLinkedList, head1);
			head2->next = NULL;
			addNodeToList(finalLinkedList, head2);

		}
		else
		{
			head2->next = NULL;
			addNodeToList(finalLinkedList, head2);
			head1->next = NULL;
			addNodeToList(finalLinkedList, head1);

		}
		length += 2;
	}
	return length;
}