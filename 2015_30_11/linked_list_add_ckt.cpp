#pragma warning(disable:4996)
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node * reverse(struct node *, struct node *);
void adder(struct node*, struct node*);
int validation(struct node*head1, struct node*head2);
void verify(struct node*head1, struct node*head2, int carry);
struct node * numberToLinkedList(int N);
struct node{
	int data;
	struct node *next;
};
struct test{
	int input1;
	int input2;
}test[10] = {
	{123,432},
	{999,999},
	{213,2432},
	{2432,213},
	{1,133432},
	{0,2311},
	{0,0},
	{0,12},
	{13,0}
};
struct node *newnode(int);
void print(struct node*);
void fun(struct node *head1, struct node *head2, int carry);
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
struct node * reverse(struct node * head, struct node *pre){
	struct node *new_head;
	if (head == NULL){
		return NULL;
	}
	else if (head->next == NULL){
		head->next = pre;
		return head;
	}
	else{
		new_head = reverse(head->next, head);
		head->next = pre;
		return new_head;
	}
}
void main(){
	for (int i = 0; i < 9; i++){
		adder(reverse(numberToLinkedList(test[i].input1),NULL), reverse(numberToLinkedList(test[i].input2),NULL));
	}
	getch();
}
void adder(struct node *head1, struct node *head2){
	int sum = 0, carry = 0;
	struct node  *head = head1;
	if (validation(head1,head2)){
		printf("\n Wrong input");
	}
	else{
		while ((head1->next != NULL) && (head2->next != NULL)){
			sum = head1->data + head2->data + carry;
			carry = 0;
			if (sum > 9){
				carry = sum / 10;
				sum %= 10;
			}
			head1->data = sum;
			head1 = head1->next;
			head2 = head2->next;
		}
		verify(head1,head2,carry);
		print(reverse(head, NULL));
	}
}
void fun(struct node *head1,struct node *head2,int carry){
	head1->data += carry + head2->data;
	carry = 0;
	if (head1->data > 9){
		carry = head1->data / 10;
		head1->data %= 10;
	}
	head2 = head2->next;
	if (carry > 0){
		head2->data += carry;
	}
	if (head2){
		head1->next = head2;
	}
}
void verify(struct node*head1, struct node*head2, int carry){
	if (head1->next != NULL){
		fun(head1, head2, carry);
	}
	else if (head2->next != NULL){
		fun(head1, head2, carry);
	}
	else if ((!head1->next) && (!head2->next)){
		head1->data += carry + head2->data;
		if (head1->data > 9){
			carry = head1->data / 10;
			head1->data %= 10;
			head1->next = newnode(carry);
		}
	}
}
void print(struct node *cur){
	if (!cur){
		printf("\n");
	}
	else{
		printf("%d", cur->data);
		print(cur->next);
	}
}
int validation(struct node*head1, struct node*head2){
	if (!head1&&!head2){
		printf("\n both lists are empty");
		return 1;
	}
	else if (!head1){
		print(head2);
		return 1;
	}
	else if (!head2){
		print(head1);
		return 1;
	}
	else{
		return 0;
	}
}
