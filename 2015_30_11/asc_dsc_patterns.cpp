#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
struct test{
	int input;
}test[5] = {
	1234765,
	1276354
};
struct node{
	int data;
	struct node*next;
};
struct node *newnode(int);
void mergeSplit(node *head); 
node* mergeSort(node *head,node *, node *cur);
void print(struct node *head);
void fix_list(node *);
struct node* reverse(struct node *head, struct node *cur, struct node *pre,struct node *);
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
	for (int i = 0; i < 2; i++){
		fix_list(numberToLinkedList(test[i].input));
	}
	_getch();
}
void fix_list(node *head){
	node *first = head, *pre1=NULL,*pre2=NULL,*second=NULL;
	while (first)
	{
		if (first->next){
			if (first->data < first->next->data){
				pre1 = first;
				first = first->next;
			}
			else{
				second = first;
				node *temp = second;
				while (second->next != NULL){
					if (second->data>second->next->data){
						pre2 = second;
						second = second->next;
					}
					else{
						second = pre2;
						break;
					}
				}
				pre1->next = reverse(first, first, second->next, second->next);
				first = temp->next;
			}
		}
		else{
			break;
		}
	}
	mergeSplit(head);
	print(head);
}
struct node* reverse(struct node *head, struct node *cur, struct node *pre,struct node *end){
	if (cur->next==end){
		head = cur;
		head->next = pre;
		return head;
	}
	else{
		struct node *temp = cur->next;
		cur->next = pre;
		return reverse(head, temp, cur,end);
	}
}
void print(struct node *head){
	printf("\n");
	while (head != NULL){
		printf("%d", head->data);
		head = head->next;
	}
}
void mergeSplit(node *head){
	node *cur = head;
	while (cur->next){
		if (cur->data < cur->next->data){
			cur = cur->next;
		}
		else{
			mergeSplit(cur->next);
			head=mergeSort(head,cur,cur->next);
		}
	}
}
node* mergeSort(node *head,node *pre,node *cur){
	while (head&&cur){
		if (head->next->data > cur->data){
			node *temp = head->next;
			head->next = cur;
			while (cur->next){
				cur = cur->next;
			}
			pre->next = cur->next;
			cur->next = temp;
			break;
		}
		else if (head->data < cur->data){
			head = head->next;
		}
	}
	return head;
}
