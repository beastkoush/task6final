#ifndef Make_Sales
#define Make_Sales

#include "header.h"

int make_sales(void){
	
	int customer_ID, Product_ID, quntity;
	
    printf("\nEnter date of sale (DD/MM/YYYY): ");
    scanf("%d/%d/%d",&newSALES.date,&newSALES.month,&newSALES.year);
  //  printf("%d/%d/%d",newSALES.date,newSALES.month,newSALES.year);
	printf("Enter customer ID: ");
    scanf("%d",&customer_ID);
    fseek(customer_file, customer_ID * sizeof(newCUSTOMER), SEEK_SET);
    
    if(fread(&newCUSTOMER, sizeof(newCUSTOMER), 1, customer_file)!=0)
    {
        strcpy(newSALES.fname,newCUSTOMER.fname);
        strcpy(newSALES.lname,newCUSTOMER.lname);
        strcpy(newSALES.cphonenumber,newCUSTOMER.phonenumber);
        newSALES.customerid=newCUSTOMER.cid;
    }
    else
    {
        printf("\nCustomer does not exist in system. Please enter data manually.\n");
        return 0;
    }
	
	 
    printf("Enter the Product ID: ");
    scanf("%d",&Product_ID);
    fseek(product_file, Product_ID * sizeof(newPRODUCTS), SEEK_SET);
    
    if(fread(&newPRODUCTS, sizeof(newPRODUCTS), 1, product_file)==0)
    {
        printf("Product does not exist.");
        return 0;
    }
    
    printf("Enter the number of products ordered: ");
    scanf("%d",&newSALES.num);
    quntity = atoi(newPRODUCTS.is);
    
    if(quntity<newSALES.num)
    {
        printf("Sorry, only %d are available in stock.",quntity);
        return 0;
    }
    else
	{
    	printf("%d items in stock\n",quntity);
        
        strcpy(newSALES.pname,newPRODUCTS.name);
        newSALES.tc=newPRODUCTS.uc*newSALES.num;
	}
        
    if(get_supplier_record())
    {
        strcpy(newSALES.sname,newSUPPLIER.name);
        strcpy(newSALES.scompany,newSUPPLIER.cname);
    }
    else
    {
        printf("Supplier does not exist in system. Please enter data manually.\n");
        return 0;
    }
    
    fseek(sales_file,newSALES.said*sizeof(struct sales), SEEK_SET);
    fwrite(&newSALES,sizeof(struct sales),1,sales_file);
    printf("\nThe folloing Sale is made:\n");
    printf("\n Customer Name (FN LN): %s %s\n Customer ID: %d\n Product Name: %s\n Quantity: %d\n Total Cost: %.2f\n Supplier Name: %s\n Company Name: %s\n",newSALES.fname, newSALES.lname,newSALES.customerid,newSALES.pname,newSALES.num, newSALES.tc,newSALES.sname,newSALES.scompany);
    newSALES.said++;
    fclose(sales_file);
    open_files();
    return 0;
}

#endif
