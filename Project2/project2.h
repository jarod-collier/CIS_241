#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef PROJECT2_H
#define PROJECT2_H

	typedef struct LL {
		char name[100];
		char unit[100];
		int price;
		int quantity;
		struct LL *next;
	} product ;

product *createList(product *head);
void insertProduct(product *node);
void deleteProduct(product *node);
product *deleteEntireList(product *node);
int searchProduct(product *head);
void display(product *head);
void purchase(product *node);
void sell(product *head);
void save(product *head); 

#endif
