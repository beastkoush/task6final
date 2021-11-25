#ifndef Open_File
#define Open_File

#include "header.h"

// Function to open binary file
void open_files(void)
{
	// Checking if files exist aready, if not, open them for reading and writing
	if((customer_file=fopen("customer.dat","rb+"))==NULL)
	{
	    customer_file=fopen("customer.dat","wb+");
	    fclose(customer_file);
	    customer_file=fopen("customer.dat","rb+");
	}
	if((supplier_file=fopen("supplier.dat","rb+"))==NULL)
	{
	    supplier_file=fopen("supplier.dat","wb+");
	    fclose(supplier_file);
	    supplier_file=fopen("supplier.dat","rb+");
	}
	if((product_file=fopen("product.dat","rb+"))==NULL)
	{
	    product_file=fopen("product.dat","wb+");
	    fclose(product_file);
	    product_file=fopen("product.dat","rb+");
	}
	if((sales_file=fopen("sales.dat","rb+"))==NULL)
	{
	    sales_file=fopen("sales.dat","wb+");
	    fclose(sales_file);
	    sales_file=fopen("sales.dat","rb+");
	}
}

#endif
