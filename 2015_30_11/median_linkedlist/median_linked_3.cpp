#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node{
	int data;
	struct node *next;
};
struct test{
	int in;
}test[5] = {
	213,
	3235,
	53231,
	0,
	1
}
;
void median(struct node *,struct node *,struct node *);
struct node * numberToLinkedList(int N);
struct node *newnode(int);
struct node * numberToLinkedList(int N) {
	struct node *head, *new_node;
	head = (struct node*)malloc(sizeof(struct node));
	new_node = (struct node*)malloc(sizeof(struct node));
	if (N < 0){
		N *= -1;
	}
	head = newnode(N % 10);
	N /= 10;
	while (N>0){
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node = newnode(N % 10);
		new_node->next = head;
		head = new_node;
		N /= 10;
	}
	return head;
}
struct node * newnode(int in){
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = in;
	new_node->next = NULL;
	return new_node;
}
void main()
{
	struct node *head;
	for (int i = 0; i < 5; i++){
		head = (struct node*)malloc(sizeof(struct node));
		head = numberToLinkedList(test[i].in);
		median(head,head,head);
	}
	getch();
}
void median(struct node *head, struct node *ptr1, struct node *ptr2){
	if (ptr2->next != NULL){
		if (ptr2->next->next != NULL){
			median(head, ptr1->next, ptr2->next->next);
		}
		else{
			printf("\n medians are %d,%d", ptr1->data, ptr1->next->data);
		}
	}
	if (ptr2->next == NULL){
		printf("\n median is %d", ptr1->data);
	}
}