#include"project2.h"
int main()
{
	int choice;
	product *node = NULL;
	
	printf("\n1:  Create an empty list\t");
	printf("2:  Insert a product");					//line 1

	printf("\n3:  Delete a product\t\t");
	printf("4:  Delete the entire list");			//line 2

	printf("\n5:  Search a product\t\t");
	printf("6:  Display products in the list");		//line 3

	printf("\n7:  Purhase a product\t\t");
	printf("8:  Sell a product");					//line 4

	printf("\n9:  Save to file\t\t");
	printf("0:  Exit\n\n");							//line 5
	
	printf("Please select an option: ");
	scanf("%d", &choice);
	
	while (choice != 0){
		if (choice == 1){
			node = createList(node);
			printf("Please select an option: ");
			scanf("%d", &choice);
		}
		else if (choice == 2) {
			if (node != NULL){
				insertProduct(node);
				//node = insertProduct(node);
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
			else{
				printf("You must create a list first\n");
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
			
		}
		else if (choice == 3){
			if (node!= NULL){
				deleteProduct(node);
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
			else{
				printf("You must create a list first\n");
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
		}
		else if (choice == 4) {
			if (node!= NULL){
				node = deleteEntireList(node);
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
			else{
				printf("You must create a list first\n");
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
		}
		else if (choice == 5){
			if (node!= NULL){
				if (searchProduct(node) == 1)
					printf("Product found\n");
				else
					printf("Product does not exist\n");
			
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
			else{
				printf("You must create a list first\n");
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
		}
		else if (choice == 6){
			if (node != NULL){
				display(node);
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
			else{
				printf("You must create a list first\n");
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
		}
		else if (choice == 7){
			if (node != NULL){
				purchase(node);
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
			else{
				printf("You must create a list first\n");
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
		}
		else if (choice == 8){
			if (node != NULL){
				sell(node);
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
			else{
				printf("You must create a list first\n");
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
		}
		else if (choice == 9){
			if (node != NULL){
				save(node);
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
			else{
				printf("You must create a list first\n");
				printf("Please select an option: ");
				scanf("%d", &choice);
			}
		}
		else{
			printf("Please choose a valid option\n");
			printf("Please select an option: ");
			scanf("%d", &choice);
		}
	}

	return 0;
}
