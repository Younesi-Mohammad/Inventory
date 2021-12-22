#include "defs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//get id of a product to sell or buy it
int get_id(){
	int idntfr, temp=0;
	system("cls");
    printf("Enter product ID:");
	temp = scanf (" %d", &idntfr);
	//check if the entered id is an integer
    if (temp != 1){
        int c = getchar();
		while (c != '\n' && c != EOF)
        	c = getchar();
        printf("Product ID is a digit!");
        printf("\nPlease Enter 'e' character to continue...");
    	char cont = '1';
    	while(cont != 'e' && cont != 'E'){
        	cont = getchar();
    	}
        return 0;
    }
    else
        return idntfr;
}

/*******************************************/
//check validity of the entered id by user to sell or add product
int check_id(InventoryType store, int id){
	int i=0;
	//check if there is a produt with the entered id
	while(store.products->next_id - i > 1001){
		if(store.products->products_arr[i]->id == id)
			return 1;
		i++;
	}
	printf("Invalid product ID!");
	printf("\nPlease Enter 'e' character to continue...");
    char cont = '1';
    while(cont != 'e' && cont != 'E'){
        cont = getchar();
    }
    return 0;
}

/*******************************************/
//get number of units of the product that user wants to add
int get_num_of_stock(){
	int num, temp=0;
	system("cls");
    printf("Enter number of stock you want to add:");
	temp = scanf (" %d", &num);
	//check if number of stock to be added is an integer
    if (temp != 1){
        int c = getchar();
		while (c != '\n' && c != EOF)
        	c = getchar();
        printf("Number of stock is a digit!");
        printf("\nPlease Enter 'e' character to continue...");
    	char cont = '1';
    	while(cont != 'e' && cont != 'E'){
        	cont = getchar();
    	}
        return 0;
    }
   	//check if number of stock to be added is greater than 0
    if(num<1){
    	printf("Number of stock cannot be less than 1!");
        printf("\nPlease Enter 'e' character to continue...");
    	char cont = '1';
    	while(cont != 'e' && cont != 'E'){
        	cont = getchar();
    	}
        return 0;
	}
    else
        return num;
}

/*******************************************/
//add specific number of units of a product having id to the array 
void add_stock(ProductArrType** products, int id, int num){
	int i=0;
	//add number of units to a product having entered id
	while((*products)->next_id - i > 1001){
		if((*products)->products_arr[i]->id == id){
			(*products)->products_arr[i]->num_of_units += num;
			printf("\nStock added!\n");
			printf("\nPlease Enter 'e' character to continue...");
    		char cont = '1';
    		while(cont != 'e' && cont != 'E'){
        		cont = getchar();
    		}
			break;
		}
		i++;
	}
}

/*********************************************/
//decrement num_of_units of the product having id and add it's price to accumulated total of user
void buy_product(ProductArrType** products, int id, float* total){
	int i=0;
	//buy a product having entered id and add it's price to accumulated total of user
	while((*products)->next_id - i > 1001){
		if((*products)->products_arr[i]->id == id){
			//check if the product is available
			if((*products)->products_arr[i]->num_of_units > 0){
				(*products)->products_arr[i]->num_of_units -= 1;
				*total += (*products)->products_arr[i]->price;
				printf("\nStock added!\n");
			}
			else
				printf("This product is no more available!\n");
			printf("\nPlease Enter 'e' character to continue...");
    		char cont = '1';
    		while(cont != 'e' && cont != 'E'){
        		cont = getchar();
    		}
			break;
		}
		i++;
	}
}

