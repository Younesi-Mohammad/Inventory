#include "defs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/********************************************/
//free all dynamically allocated memory
void free_memory(InventoryType store){
	int i=0;
	for(i; i<store.products->num_of_products; i++){
		free(store.products->products_arr[i]);
	}
	free(store.products);
}
