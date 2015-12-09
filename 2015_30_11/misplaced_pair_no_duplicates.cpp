#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
void fun(struct node *,struct node *);
void print(node *);
struct node * numberToLinkedList(int N);
void swap(node *head,node *p1, node *p2,int head_flag);
struct node{
	int data;
	struct node *next;
};
struct test{
	int input;
}test[10] = {
	12645378,
	52341,
	15342,
	12543,
	12354,
	21345,
	32145,
	42315,
	1238749,
	113245
};
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
	for (int i = 0; i < 10; i++){
		fun(numberToLinkedList(test[i].input),NULL);
		getch();
	}
}
void fun(struct node*head, struct node*pre){
	struct node *cur, *p1 = head, *p2 = NULL;
	int flag = 0,head_flag=0;
	cur = head;
	while (cur->next != NULL){
		if (!flag){
			if (cur->data > cur->next->data){
				if (!pre){//head
					flag = 1;
					head_flag = 1;
				}
				else {
					p1 = pre;
					flag = 1;
				}
			}
		}
		else {
			if ((p1 == head) && (cur->next->data > p1->data)&&(head_flag)){
				p2 = pre;
				break;
			}
			if ((p1!=head)&&(cur->next->data > p1->next->data)){
				p2 = pre;
				break;
			}
			else if (!cur->next->next){
				p2 = cur;
				break;
			}
		}
		pre = cur;
		cur = cur->next;
	}
	if (!p2){
		p2 = pre;
	}
	swap(head, p1, p2,head_flag);
}
void swap(node *head,node *p1, node *p2,int head_flag){
	if (p1&&p2){
		if ((p1 == head) && head_flag&&(p1!=p2)){
			node *temp = p1->next;
			p1->next = p2->next->next;
			head = p2->next;
			head->next = temp;
			p2->next = p1;
			print(head);
		}
		else if ((p1->next == p2)&&(!p2->next->next)){
			node *temp = p1->next;
			p1->next = p2->next;
			temp->next = p1->next->next;
			p1->next->next = temp;
			print(head);
		}
		else if ((p1->next == p2)){
			node *temp = p1->next;
			p1->next = p2->next;
			temp->next = p1->next->next;
			p1->next->next = temp;
			print(head);
		}
		else if (p1 == p2){
			p1->data = p1->data + p1->next->data;
			p1->next->data = p1->data - p1->next->data;
			p1->data = p1->data - p1->next->data;
			print(head);
		}
		else{
			node*temp = p2->next->next;
			p2->next->next = p1->next->next;
			p1->next->next = temp;
			temp = p2->next;
			p2->next = p1->next;
			p1->next = temp;
			print(head);
		}
	}
}
void print(node * head){
	if (!head){
		printf("\n");
	}
	else{
		printf("%d", head->data);
		print(head->next);
	}
}