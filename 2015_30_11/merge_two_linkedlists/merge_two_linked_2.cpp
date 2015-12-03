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
	{ 146, 2358 },
	{ 123, 123 },
	{ 1234567, 1 }
};
void merge(struct node*, struct node*,struct node*);
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
	struct node *head1, *head2, *head;
	for (int i = 0; i < 4; i++){
		head1 = (struct node*)malloc(sizeof(struct node));
		head2 = (struct node*)malloc(sizeof(struct node));
		head = (struct node*)malloc(sizeof(struct node));
		head1 = numberToLinkedList(test[i].in_1);
		head2 = numberToLinkedList(test[i].in_2);
		if (head1->data <= head2->data){
			head = head1;
			head1=head1->next;
		}
		else{
			head = head2;
			head2 = head2->next;
		}
		merge(head1->next, head2,head);
		while (head!=NULL)
		{
			printf("\t %d", head->data);
			head = head->next;
		}
		printf("\n");
	}
	getch();
}
void merge(struct node *head1,struct node *head2,struct node *cur){
	if ((head1 != NULL) && (head2 != NULL)){
		if ((head1->data) <= (head2->data)){
			cur->next = head1;
			merge(head1->next, head2,cur->next);
		}
		else{
			cur->next = head2;
			merge(head1, head2->next,cur->next);
		}
	}
	else if (head1 != NULL){
		cur->next = head1;
	}
	else if (head2 != NULL){
		cur->next = head2;
	}
}