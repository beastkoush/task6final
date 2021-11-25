//
//  main.c
//  task6
//
//  Created by Koush on 2021-11-21.
//

#include "header.h"

int main(int argc, char* argv[])
{
    newCUSTOMER.cid=1000;
    newSUPPLIER.sid=1000;
    newPRODUCTS.pid=1;
    newSALES.said=1;
    open_files();
    
    int i, option=0,option2=0;
    
    for(i=0; option!=6; i++)
    {
    printf("\n\nStellarton Solar Systems\n\nMain Menu\n\n");
    printf("Select one of the following: \n");
    printf("1: Add new Customers\n");
    printf("2: Add new Suppliers\n");
    printf("3: Add new Products\n");
    printf("4: Make sales\n");
    printf("5: Read Data\n");
    printf("0: Exit\n\n");
    printf("Option #: ");
    scanf("%d",&option);
    
    switch (option)
    {
        case 0:
            printf("Program Terminated.\n");
            return 0;
        case 1:
            get_customer_data();
        break;
        case 2:
            get_supplier_data();
        break;
        case 3:
            get_product_data();
            break;
        case 4:
            make_sales();
            break;
        case 5:
            printf("\nSelect one of the following: \n");
            printf("1: Read Customer data\n");
            printf("2: Read Supplier data\n");
            printf("3: Read Product data\n");
            printf("4: Read Sales data\n");
            printf("0: Main Menu\n");
            printf("\nOption #: ");
            scanf("%d",&option2);
            if(option2>4||option2<0)
            {
                printf("Invalid entry. Please try again.\n");
                break;
            }else if(option2 == 0)
            {
                break;
            }
            read_data(option2);
            break;
        default:
            printf("Invalid entry. Please try again.\n");
            break;
    }
    }
    
    fclose(supplier_file);
    fclose(customer_file);
    fclose(product_file);
    fclose(input_file);
    
    getchar();
    return 0;
}







