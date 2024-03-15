#include<stdio.h>
#include<stdlib.h>


//void display(struct node *);
//int count_nodes(struct node*);
struct node* insert_at_beginning(struct node *head, int data);
struct node* insert_at_position(struct node *head, int data, int pos);
struct node* insert_at_end(struct node *head, int data) ;
struct node* delete_at_beginning(struct node *head);
struct node* delete_at_position(struct node *head, int pos);
struct node* delete_at_end(struct node *head) ;
int search(struct node *head, int key);
struct node* insert_at_after_position_(struct node *head, int data, int pos) ;


struct node {
    int data;
    struct node *next, *prev;
};

void display(struct node *head) {

    struct node *ptr;
    ptr=head;
    printf("ELEMENT IN LINKED LIST:");
    while(ptr!=NULL) {

        printf("%d  ",ptr->data);
        ptr=ptr->next;

    }

}

int count_nodes(struct node* head) {
    struct node *ptr=head;
    int count =0;
    while(ptr!=NULL) {
        count++;
        ptr=ptr->next;

    }
    return count;
}

struct node* insert_at_beginning(struct node *head, int data) {
    struct node *ptr;
    ptr=malloc(sizeof(struct node)) ;
    ptr->prev=NULL;
    ptr->data=data;
    ptr->next=NULL;
    head->prev=ptr;
    ptr->next=head;

    head=ptr;
    return head;
}
struct node* insert_at_end(struct node *head, int data) {
    struct node *ptr, *temp;
    ptr=head;
    temp=malloc(sizeof(struct node)) ;
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    while(ptr->next!=NULL) {
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    return head;
}


struct node* insert_at_position(struct node *head, int data, int pos) {
    int size=count_nodes(head) ;

    if(head==NULL) {
        printf("list is already empty");
    }
    else if(size<pos) {
        return insert_at_end(head, data) ;
        // return head;
    }
    else if(pos==1) {
        insert_at_beginning(head, data) ;

    }
    else {

        struct node *ptr, *ptr1, *temp;
        ptr=head;
        temp=malloc(sizeof(struct node)) ;
        ptr1=malloc(sizeof(struct node)) ;
        temp->prev=NULL;
        temp->data=data;
        temp->next=NULL;
        pos--;
        while(pos>1) {
            ptr=ptr->next;
            pos--;
        }
        ptr1=ptr->next;
        ptr->next=temp;
        ptr1->prev=temp;
        temp->next=ptr1;
        temp->prev=ptr;
        return head;
    }
}
struct node* insert_at_after_position(struct node *head, int data, int pos) {
    int size=count_nodes(head) ;

    if(head==NULL) {
        printf("list is already empty");
    }
    else if(size==pos) {
        return insert_at_end(head, data) ;
        // return head;
    }
    else if(pos==1) {
        insert_at_beginning(head, data) ;

    }
    else {

        struct node *ptr, *ptr1, *temp;
        ptr=head;
        temp=malloc(sizeof(struct node)) ;
        ptr1=malloc(sizeof(struct node)) ;
        temp->prev=NULL;
        temp->data=data;
        temp->next=NULL;
        //pos--;
        while(pos>1) {
            ptr=ptr->next;
            pos--;
        }
        ptr1=ptr->next;
        ptr->next=temp;
        ptr1->prev=temp;
        temp->next=ptr1;
        temp->prev=ptr;
        return head;
    }
}

struct node* delete_at_beginning(struct node *head) {
    struct node *ptr;
    ptr=head;
    head=head->next;
    ptr->next=NULL;
    head->prev=NULL;
    free(ptr) ;
    return head;
}
struct node* delete_at_end(struct node *head) {
    struct node *ptr, *temp ;
    temp =malloc(sizeof(struct node)) ;
    while(ptr->next!=NULL) {
        temp=ptr;
        ptr=ptr->next;
    }

    temp->next=NULL;
    free(ptr) ;
    return head;
}

struct node* delete_at_position(struct node *head, int pos) {
    int count=count_nodes(head) ;
    if(pos==1) {
        head=delete_at_beginning(head) ;
        return head;
    }
    else if(count==pos) {
        head=delete_at_end(head);
        return head;
    }
    else {
        struct node *ptr, *temp ;
        ptr=head;
        temp=malloc(sizeof(struct node*)) ;
        while(pos!=1) {
            temp=ptr;
            ptr=ptr->next;
            pos--;
        }
        temp->next=ptr->next;
        ptr->next->prev=temp;

        free(ptr) ;
        return head;
    }

}



int search(struct node *head, int key) {
    struct node *ptr, *temp;
    temp=(struct node*)malloc(sizeof(struct node*)) ;
    ptr=head;
    int node, pos;
    while(ptr!=NULL) {
        if(ptr->data==key) {
            temp=ptr;
            //  node=count_nodes(temp) ;
            return node;
        }
        node++;
        ptr=ptr->next;

    }
    if(pos<=0) {
        return -1;

    }
}




int main() {
    struct node *head;
    head=malloc(sizeof(struct node)) ;
    head->prev=NULL;
    head->data=15;
    head->next=NULL;
    head=insert_at_beginning(head, 10);
    head=insert_at_beginning(head, 5);
    //head=insert_at_position(head, 15, 2);
    head=insert_at_after_position(head, 20, 3);
    //head=insert_at_end(head, 50);
    // head=delete_at_beginning(head) ;
  //  head= delete_at_position(head,2);
    //head=delete_at_end(head);
    display(head) ;
    int size=count_nodes(head) ;
    int key;
    printf("\nnodes=%d", size);
    printf("\nenter the element to search:");
    scanf("%d", &key);
    int node=search(head, key);
    if(node==-1) {
        printf("Element is not found\n");
    }
    else {
        printf("Element is found at %d", 1+node);

    }
    return 0;

}


