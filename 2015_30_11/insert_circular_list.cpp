#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
void insert(struct node*,int);
struct node{
	int data;
	struct node *next;
};
struct test{
	int in;
	int k;
}test[8] = {
	{ 2345, 1 },//at head
	{ 12345, 1 },//next to head
	{1245,3},//morethan head
	{12345,3},//morethan head with duplicate
	{ 1, 0},//single element insertion at head
	{ 0, 1 },//single element insertion at tail
	{111111, 1},//all are dup insert at next to head
	{11112,2}//insert next to tail
};
struct node *newnode(int);
void print(struct node*);
void insertAtCurrent(struct node *cur, int data);
struct node* insertAtHead(struct node *cur, struct node*head, int data);
struct node * numberToCircularLinkedList(int N) {
	struct node *head, *new_node;
	head = (struct node*)malloc(sizeof(struct node));
	if (N < 0){
		N *= -1;
	}
	if (N < 10){
		head = newnode(N);
		head->next = head;
		return head;
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
	if (N == 0){
		new_node = head;
			while (new_node->next != NULL){
				new_node = new_node->next;
			}
			new_node->next = head;
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
	for (int i = 0; i < 8; i++){
		head = numberToCircularLinkedList(test[i].in);
		insert(head,test[i].k);
	}
	getch();
}
void insert(struct node * head,int data){
	struct node *cur;
	cur = (struct node *)malloc(sizeof(struct node));
	cur = head;
	if (head == NULL){
		head = numberToCircularLinkedList(data);
		printf("\n%d", head->data);
	}
	else{
		do{
			if (cur->data == data){
				insertAtCurrent(cur, data);
				break;
			}
			else if (head->data > data){
				head=insertAtHead(cur, head, data);
				break;
			}
			else if ((cur->next != NULL) && (cur->data<data) && (cur->next->data>data)){
				insertAtCurrent(cur, data);
				break;
			}
			else if (cur->next != head){
				cur = cur->next;
			}
			else if ((cur->data < data) && (cur->next == head)){
				insertAtCurrent(cur, data);
				break;
			}
		} while (cur != head);
		print(head);
	}
}
void print(struct node *head){
	struct node *cur;
	cur = (struct node*)malloc(sizeof(struct node));
	cur = head;
	printf("\n");
	do{
		printf("%d", cur->data);
		cur = cur->next;
	} while (cur != head);
}
void insertAtCurrent(struct node *cur, int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = cur->next;
	cur->next = temp;
}
struct node* insertAtHead(struct node *cur,struct node*head,int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	while (cur->next != head){
		cur = cur->next;
	}
	cur->next = temp;
	temp->next = head;
	head = temp;
	return head;
}