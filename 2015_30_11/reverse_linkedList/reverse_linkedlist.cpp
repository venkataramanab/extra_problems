#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node * reverse(struct node *,struct node *);
struct node{
	int data;
	struct node *next;
};
struct test{
	int in;
}test[5] = {
	12345,
	1,
	0,
	123,
	22221
};
struct node *newnode(int);
void print(struct node*);
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
	struct node *head;
	head = (struct node*)malloc(sizeof(struct node));
	for (int i = 0; i < 5; i++){
		head = numberToLinkedList(test[i].in);
		if (head != NULL){
			head=reverse(head,NULL);
			print(head);
		}
	}
	getch();
}
struct node * reverse(struct node * head,struct node *pre){
	if (head->next == NULL){
		head->next = pre;
		return head;
	}
	else{
		struct node *new_head = reverse(head->next, head);
		head->next = pre;
		return new_head;
	}
}
void print(struct node *head){
	printf("\n");
	while (head != NULL){
		printf("%d", head->data);
		head = head->next;
	}
}