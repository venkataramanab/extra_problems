#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node{
	int data;
	struct node *next;
};
struct test{
	int in_1;
	int in_2;
}test[5] = {
	{ 135, 246 },
	{146,2358},
	{123,123},
	{1234567,1}
};
void merge(struct node*, struct node*);
struct node * numberToLinkedList(int);
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
void main(){
	for (int i = 0; i < 4; i++){
		merge(numberToLinkedList(test[i].in_1),numberToLinkedList(test[i].in_2));
	}
	getch();
}
void merge(struct node *head1, struct node *head2){
	struct node *cur,*head;
	cur = (struct node*)malloc(sizeof(struct node));
	if (head1->data <= head2->data){
		cur = head1;
		head = cur;
		head1 = head1->next;
	}
	else{
		cur = head2;
		head = head2;
		head2 = head2->next;
	}
	while ((head1 != NULL) && (head2 != NULL)){
		if (head1->data < head2->data){
			cur->next = head1;
			head1 = head1->next;
			cur = cur->next;
		}
		else{
			cur->next = head2;
			head2 = head2->next;
			cur = cur->next;
		}
	}
	if (head1 != NULL){
		cur->next = head1;
	}
	else if (head2 != NULL){
		cur->next = head2;
	}
	cur = head;
	while (cur != NULL){
		printf("%d", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
