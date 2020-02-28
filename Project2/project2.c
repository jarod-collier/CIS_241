#include"project2.h"
product *createList(product *head) {
	head = (product *)malloc(sizeof(product));
	head->next = NULL;
	return head;
}

void insertProduct(product *head){
	product *node = (product *)malloc(sizeof(product));
	printf("Define product's information as name, unit, price, quantity:\n");
	scanf("%s %s %d %d", &node->name, &node->unit, &node->price, &node->quantity);

	if (node->price > 0 && node->quantity > 0){
		
		//Purchases anywhere else in the list
		while (head->next!= NULL) {
			
			if (strcmp(head->next->name, node->name) == 0){
				printf("Please enter a valid product to insert\n");
				return;
			}
			head = head->next;
		}
		
		node-> next= head->next;
		head->next = node;
	}
	else{
		printf("The price and quantity must be greater than 0 \n");
	}
}

void deleteProduct(product *head){
	char find[100];
	int search = 0;
	printf("Type the name of the product you would like to delete: ");
	scanf("%s", &find);
	
	
	//Deletes the head of the list if only element
	if(head->next->next == NULL){
		if (strcmp(head->next->name, find) == 0){
			search = 1;
			
			head->next = head->next->next;
			free(head->next);
			return;
		}
	}
	
	//Deletes anywhere else in the list
	while (head->next != NULL) {
		
		if (strcmp(head->next->name, find) == 0){
			search = 1;
			
			product *tmp = head->next;
			head->next = head->next->next;
			free(tmp);
			return;
		}
		head = head->next;
	}
	
	if (search == 0){
		printf("Please enter a valid product to delete\n");
	}	
	
}

product *deleteEntireList(product *head){
	
	while (head != NULL) {
		product *tmp = head;
		head = head->next;
		free(tmp);
	}
	return head;
}

int searchProduct(product *head){
	char find[100];
	printf("Type the name of the product to find: ");
	scanf("%s", &find);
	
	while (head!= NULL) {
		if (strcmp(head->next->name, find) == 0)
			return 1;
		head = head->next;
	}
	return 0;
	
}

void display(product *head){
	
	head = head->next;

	while(head != NULL){
		printf("%s %s %d %d\n", head->name, head->unit, head->price, head->quantity);
		head = head->next;
	}
}

void purchase(product *head){
	
	char find[100];
	int search = 0;
	printf("Type the name of the product you want to purchase: ");
	scanf("%s", &find);
	
	//Purchases the head of the list if only element
	if(head->next->next == NULL){
		if (strcmp(head->next->name, find) == 0){
			search = 1;
			head->next->quantity++;	
			return;
		}
	}
	
	//Purchases anywhere else in the list
	while (head->next != NULL) {
		
		if (strcmp(head->next->name, find) == 0){
			search = 1;
			head->next->quantity++;
		}
		head = head->next;
	}
	
	if (search == 0){
		printf("Please enter a valid product to purchase\n");
	}	
}

void sell(product *head){
	
	char find[100];
	int search = 0;
	printf("Type the name of the product you want to sell: ");
	scanf("%s", &find);
	
	//Deletes the head of the list if only element
	if(head->next->next == NULL){
		if (strcmp(head->next->name, find) == 0){
			search = 1;
			head->next->quantity--;
			
			if (head->next->quantity == 0){
			head->next = head->next->next;
			free(head->next);
			}	
		return;
		}
	}
	
	//Deletes anywhere else in the list
	while (head->next != NULL) {
		
		if (strcmp(head->next->name, find) == 0){
			search = 1;
			head->next->quantity--;
			
			if (head->next->quantity == 0){
			
			product *tmp = head->next;
			head->next = head->next->next;
			free(tmp);
			}
		}
		head = head->next;
	}
	
	if (search == 0){
		printf("Please enter a valid product to sell\n");
	}
}

void save(product *head){
	FILE *fout;
	fout = fopen("Product_List.txt", "w");
	head = head->next;
	while (head != NULL){
		fprintf(fout, "%s %s %d %d\n", head->name, head->unit, head->price, head->quantity);
head = head -> next;
	
	}
	fclose(fout);	
} 
