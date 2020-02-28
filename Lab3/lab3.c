#include"lab3.h"

typedef struct node ELEMENT;



/*
initialize: create an empty head node (whose "data" is 
intentionally missing); 
This head node will not be used to store any data;
*/
struct node *init (){
	
	ELEMENT *node = (ELEMENT *)malloc(sizeof(ELEMENT));
	node->next = NULL;
	
	return node;
	
}

/*
Create a new node to store data and insert it to the end of current linked list; 
the head node will still be empty and data in the array in "main.c" 
are not stored in head node
*/
void insert(struct node *head, int data){
	
	ELEMENT *temp = (ELEMENT *)malloc(sizeof(ELEMENT));
	temp = head;
	
	while(temp->next != NULL)
		temp = temp->next;
	
	head = (ELEMENT *)malloc(sizeof(ELEMENT));
	head-> data = data;
	head-> next = NULL;
	
	temp->next = head;
}

/*
print data for all nodes in the linked list 
except the head node (which is empty)
*/
void display (struct node *head){

	for (;head!=NULL; head = head->next){
		printf("%d\n", head->data);
	}

}

/*
delete the entire linked list including the head node
*/
void deleteAll (struct node *head){
	
	if (head!=NULL){
		deleteAll(head->next);
		free(head);
	}
}