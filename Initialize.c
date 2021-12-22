#include "defs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Initialize InventoryType using 10 defined products
void initialize(InventoryType* store){
	//set store's name
	strcpy(store->name, "The SCS Store");
	//dynamically allocate memory to store's ProductArrType instance
	store->products = (ProductArrType*)malloc(sizeof(ProductArrType));
	store->products->num_of_products = 0;
	//set starting id of products
	store->products->next_id = 1001;
	//create 10 products and add them to store's array
	ProductType *p;
	create_product(&p, "Mobile Phone", 12, 1220.0);
	add_product(&(store->products->products_arr[store->products->num_of_products]), p, &(store->products->next_id), &(store->products->num_of_products));
	create_product(&p, "Laptop", 4, 1530.0);
	add_product(&(store->products->products_arr[store->products->num_of_products]), p, &(store->products->next_id), &(store->products->num_of_products));
	create_product(&p, "Headphone", 21, 652.0);
	add_product(&(store->products->products_arr[store->products->num_of_products]), p, &(store->products->next_id), &(store->products->num_of_products));
	create_product(&p, "DVD Player", 14, 320.0);
	add_product(&(store->products->products_arr[store->products->num_of_products]), p, &(store->products->next_id), &(store->products->num_of_products));
	create_product(&p, "PlayStation", 10, 500.0);
	add_product(&(store->products->products_arr[store->products->num_of_products]), p, &(store->products->next_id), &(store->products->num_of_products));
	create_product(&p, "XBox", 31, 450.0);
	add_product(&(store->products->products_arr[store->products->num_of_products]), p, &(store->products->next_id), &(store->products->num_of_products));
	create_product(&p, "Webcam", 8, 59.0);
	add_product(&(store->products->products_arr[store->products->num_of_products]), p, &(store->products->next_id), &(store->products->num_of_products));
	create_product(&p, "Power Bank", 17, 210.0);
	add_product(&(store->products->products_arr[store->products->num_of_products]), p, &(store->products->next_id), &(store->products->num_of_products));
	create_product(&p, "TV", 6, 1300.0);
	add_product(&(store->products->products_arr[store->products->num_of_products]), p, &(store->products->next_id), &(store->products->num_of_products));
	create_product(&p, "External Hard", 35, 250.0);
	add_product(&(store->products->products_arr[store->products->num_of_products]), p, &(store->products->next_id), &(store->products->num_of_products));
}

/*******************************************/
//create a product using name, num_of_units and it's price (id is given when adding to array)
void create_product(ProductType** p, char* name, int num, float price){
	*p = (ProductType*)malloc(sizeof(ProductType));
	strcpy((*p)->name, name);
	(*p)->num_of_units = num;
	(*p)->price = price;
}

/********************************************/
//add product to the array and increment next_id and num_of_products of array
void add_product(ProductType** product, ProductType* p, int* id, int* num){
	//dynamically allocating memory to a cell of store's array
	*product = (ProductType*)malloc(sizeof(ProductType));
	p->id = *id;
	(*product) = p;
	(*num) += 1;
	(*id) += 1;
}

