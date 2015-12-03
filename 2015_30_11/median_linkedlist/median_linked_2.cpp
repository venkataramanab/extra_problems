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
void median(struct node *);
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
	for (int i = 0; i < 5; i++){
		median(numberToLinkedList(test[i].in));
	}
	getch();
}
void median(struct node *head){
	struct node *cur;
	int len=0,mid;
	if (head == NULL){
		printf("\n Linked list is empty");
	}
	else{
		cur = (struct node*)malloc(sizeof(struct node));
		cur = head;
		while (cur != NULL){
			len++;
			cur = cur->next;
		}
		if (len % 2 == 0){
			mid = len / 2;
			cur = head;
			while ((cur != NULL) && (mid>1)){
				cur = cur->next;
				mid--;
			}
			printf("\n medians are %d,%d", cur->data, cur->next->data);
		}
		else{
			mid = len / 2;
			cur = head;
			while ((cur != NULL) && (mid>0)){
				cur = cur->next;
				mid--;
			}
			printf("\n median is %d", cur->data);
		}
	}
}