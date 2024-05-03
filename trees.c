#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next,*pre;
};
typedef struct node NODE;
NODE *head=NULL;
void create();
void insert_front(int);
void insert_last(int);
void traverse_left();
void traverse_right();
int main(){
	int pos,item;
	int ch;
	create();
	while(1){
		printf("\nMENU\n");
		printf("1.Insert front\n");
		printf("2.Insert last\n");
		printf("3.Traverse from left to right\n");
		printf("4.Traverse from right to left\n");
		printf("5.Exit\n");
	}
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch){
		case 1:	printf("Enter the element to be inserted:");
				scanf("%d",&item);
				insert_front(item);
				break;
		case 2:	printf("Enter the element to be inserted:");
				scanf("%d",&item);
				insert_last(item);
				break;
		case 3:	traverse_right();
				break;
		case 4: traverse_left();
				break;
		case 5:exit(0);
		default:printf("Invalid choice!!!\n");
	}
}
void create(){
	int item;
	char ch;
	NODE *cur,*temp;
	do{
		printf("\nEnter the element:");
		scanf("%d",&item);
		temp=(NODE*)malloc(size of(NODE));
		temp->data=item;
		if(head==NULL)
			head=cur=temp;
		else{
			cur=head;
			cur->next=temp;
			temp->pre=cur;
			cur=temp;
		}
		printf("Do you want to continue:");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	head->prev=cur->next=NULL;
}
void traverse_right(){
	NODE *cur=head;
	if(head==NULL)
		printf("\nList is empty\n");
	else{
		while(cur!=NULL){
			printf("\n%d ",cur->data);
			cur=cur->next;
		}
	}
}
void traverse_left(){
	NODE *cur=head;
	if(head==NULL)
		printf("\nList is empty\n");
	else{
		while(cur->next!=NULL){
			cur=cur->next;
		}
		while(cur!=NULL){
			printf("\n%d ",cur->data);
			cur=cur->pre;
		}
	}
}
void insert_front(int item){
	NODE *temp;
	temp=(NODE*)malloc(size of(NODE));
	temp->data=item;
	head->pre=temp;
	temp->next=head;
	temp->prev=NULL;
	head=temp;
}
void insert_last(int item){
	NODE *cur=head,*temp;
	if(head==NULL){
		printf("\nList is empty");
	}
	else{
		temp=(NODE*)malloc(size of(NODE));
		temp->data=item;
		while(cur->next!=NULL){
			cur=cur->next;
		}
		cur->next=temp;
		temp->prev=cur;
		temp->next=NULL;
	}
}


























