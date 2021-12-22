#ifndef DEFS_H 
#define DEFS_H 

#define MAX_PRODUCTS 100

typedef struct ProductType
{
	int id;
	char name[50];
	int num_of_units;
	float price;
} ProductType;

typedef struct ProductArrType
{
	ProductType* products_arr[MAX_PRODUCTS];
	int num_of_products;
	int next_id;
} ProductArrType;

typedef struct InventoryType
{
	char name[50];
	ProductArrType* products;
} InventoryType;

void initialize(InventoryType* store);
void create_product(ProductType** p, char* name, int num, float price);
void add_product(ProductType** product, ProductType* p, int* id, int* num);
int menu();
void print_all(ProductArrType* products);
int get_id();
int check_id(InventoryType store, int id);
int get_num_of_stock();
void add_stock(ProductArrType** products, int id, int num);
void buy_product(ProductArrType** products, int id, float* total);
void print_total(float total);
void free_memory(InventoryType store);

#endif

