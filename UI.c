#include "defs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//display the menu and ask user too choose what he/she wants to do
int menu(){
	int chc = 0;
	int temp = 0;
    while(chc != 1 && chc != 2 && chc != 3 && chc != 4){
        while(1){
            system("cls");
            printf("1.Print the current inventory\n2.Add stock to an existing product in the inventory\n");
			printf("3.Buy a product from the inventory\n4.Exit the program\n");
            printf("Please enter your choice (1-4):");
            temp = scanf (" %d", &chc);
            if (temp != 1){
                int c = getchar();
			    while (c != '\n' && c != EOF)
        			c = getchar();
            }
            else{
                break;
            }
        }
    }
    return chc;
}

/**********************************************/
//display all the products that exist in the array
void print_all(ProductArrType* products){
	int i=0;
	system("cls");
	printf("Current Inventory\n----------------------------------------------------\n");
	while(products->next_id - i > 1001){
		printf("%d %s ", products->products_arr[i]->id, products->products_arr[i]->name);
		printf("%d %f\n", products->products_arr[i]->num_of_units, products->products_arr[i]->price);
		i++;
	}
	printf("\nPlease Enter 'e' character to continue...");
    char cont = '1';
    while(cont != 'e' && cont != 'E'){
        cont = getchar();
    }
}

/********************************************/
//display total accumulated of the user before he/she exit the program
void print_total(float total){
	system("cls");
	printf("\nYour accumulated total is: %f", total);
	printf("\nPlease Enter 'e' character to exit...");
    char cont = '1';
    while(cont != 'e' && cont != 'E'){
        cont = getchar();
    }
}
