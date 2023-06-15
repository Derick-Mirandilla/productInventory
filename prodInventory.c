#include <stdio.h>
#include <string.h>

#define STRING_SIZE 25

typedef struct Products{
	char name[STRING_SIZE];
	int quantity;
}Products;


void printOptions(){
	printf("\nSelect One:\n");
	printf("\t1.\tAdd a new product\n");
	printf("\t2.\tEdit product quantity\n");
	printf("\t3.\tDisplay inventort\n");
	printf("\t4.\tExit program\n\n");
}

int main(void){
	
	int maxProd = 0;
	printf("Enter the maximum number of products in the inventory: ");
	scanf("%d", &maxProd);
	getchar();
	
	int i, j, choice, currentProd = 0;
	int programStatus = 1;
	char editProd[STRING_SIZE];
	
	Products product[maxProd];
	
	while(programStatus){
		printOptions();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getchar();
		printf("\n");
		
		
		switch(choice){
			case 1:
				if(currentProd == maxProd){
					printf("MAXIMUM NUMBER OF PRODUCTS REACHED!\n");
					break;
				}
				
				else{
					
					printf("Enter the name of the product: ");
					fgets(product[currentProd].name, sizeof(product[currentProd].name), stdin);
					product[currentProd].name[strcspn (product[currentProd].name, "\n")] = '\0';
					
					printf("Enter the quantity: ");
					scanf("%d", &product[currentProd].quantity);
					currentProd++;
					break;
				}
				
			
			case 2:
				if (currentProd == 0){
					printf("NO PRODUCTS IN THE INVENTORY!\n");
					break;
				}
				
				else{
					printf("Enter the name of the product to update: ");
					scanf("%s", &editProd);
					getchar();
					
					for(i = 0; i < currentProd; i++){
						if(strcmp(editProd, product[i].name) == 0){
							printf("Enter new quantity: ");
							scanf("%d", &product[i].quantity);
						}
						
						else if (strcmp(editProd, product[i].name) != 0){
							printf(("PRODUCT IS NOT IN THE INVENTORY!\n"));
						}
					}
					
					break;
				}
				
				
			case 3:
				if (currentProd == 0){
					printf("NO PRODUCTS IN THE INVENTORY!\n");
					break;
				}
				
				else{
					printf("CURRENT INVENTORY:\n\n");
					printf("PRODUCT\tQUANTITY\n");
					
					for(i = 0; i < currentProd; i++){
						printf("%s\t%d\n", product[i].name, product[i].quantity);
					}		
					break;
				}
				
				
			case 4:
				printf("EXITING PROGRAM...\n");
				programStatus = 0;
				break;
			
			default:
				printf("Invalid input! Try again.\n");
		}
	}
	
	return 0;
}
