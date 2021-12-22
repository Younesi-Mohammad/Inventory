#include "defs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	//an instance of InventoryType to keep all info
	InventoryType store;
	//initialize InventoryType instance and create and add products to it's array
	initialize(&store);
	int choice; 
	float total = 0;
	int identifier;
	int flag = 1;
	//show menu to user until he/she exits program
	while(flag){
		choice = menu();
		switch(choice){
			//print all products info
			case 1:
				print_all(store.products);
				break;
			//add stock to Inventory
			case 2:
				//get product id to add stock to it
				identifier = get_id();
				if(identifier == 0)
					break;
				//check if the id is valid
				if(check_id(store, identifier) == 0){
					break;
				}
				//get number of units user wants to add
				int num_of_stock = 0;
				num_of_stock = get_num_of_stock();
				if(num_of_stock < 1)
					break;
				//add number of specified stock to the product with the specific id
				add_stock(&(store.products), identifier, num_of_stock);
				break;
			//buy a product
			case 3:
				//get product id to buy
				identifier = get_id();
				if(identifier == 0)
					break;
				//check if the id is valid
				if(check_id(store, identifier) == 0){
					break;
				}
				//buy a product having entered id and add it's price to user's accumulated total
				buy_product(&(store.products), identifier, &total);
				break;
			//Exit program
			case 4:
				//print user's accumulated total before exiting
				print_total(total);
				//free dynamically allocated memory before exiting
				free_memory(store);
				flag = 0;
				break;
		}
	}
  	return 0;
}

