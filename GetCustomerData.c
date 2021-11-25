#ifndef Get_Customer_Data
#define Get_Customer_Data

#include "header.h"

// Function to read customer data from a text file and store it in a binary file
int get_customer_data(void)
{
	int option, x;
    char file_name[30], input_buffer[100], password[30];
	
	// Get user selection
	printf("\nSelect one of the following: \n");
    printf("1: Add multiple customers by file\n");
    printf("2: Add a singular customer\n");
    printf("0: Main Menu\n");
    printf("\nOption #: ");
    scanf("%d",&option);
    
    // If user enters 0, then exit the function
    if(option == 0){
    	return 0;
	}
    // If user enters 1, then go through the process of entering customer data by file
    else if(option==1)
    {
    	x=0;
        printf("\n -- Secure Access --\nEnter password: ");
        scanf("%s",password);
        if(strcmp(password,"password")==0)
        {
    	// Ask user to supply customer file to get the data from it
        printf("Enter name of file to read: ");
        scanf("%s",file_name);
        // Open supplied file
        if(fopen(file_name,"r")==NULL)
        {
            printf("\nInvalid File name. Please try again.\n");
            return 0;
        }
        input_file=fopen(file_name,"r");
		
		// Get all input data from the file sequntially
        while(fgets(input_buffer, 1000, input_file)>0)
        {
        	// Skip the first line in the text file as it only a title 
            if(x==0)
                x++;
            else
            {
        	// Store input data into customer struct 
            sscanf(input_buffer,"%[^ ]%*c %[^,]%*c %[^,]%*c %[^,]%*c %[^,]%*c %[^,]%*c %[^,]%*c %[^,]%*c",&newCUSTOMER.fname, &newCUSTOMER.lname,&newCUSTOMER.bname,&newCUSTOMER.sadd,&newCUSTOMER.town,&newCUSTOMER.province,&newCUSTOMER.postalcode,&newCUSTOMER.phonenumber);
            
			// Store customer data into the binary file
            fseek(customer_file,newCUSTOMER.cid*sizeof(struct customer), SEEK_SET);
            fwrite(&newCUSTOMER,sizeof(struct customer),1,customer_file);
            //Incrementing ID counter
            newCUSTOMER.cid++;
            
            fclose(customer_file);
            open_files();
            }
        }
        }else{
            printf("\nIncorrect Password. Please try again.\n");
        }
    }
    else if(option==2)
    {
        while((fread(&newCUSTOMER, sizeof(newCUSTOMER), 1, customer_file))>0)
        {
            newCUSTOMER.cid++;
        }
        // Get customer info from the user
        printf("\nCustomer ID: %d",newCUSTOMER.cid);
        printf("\nEnter First Name: ");
        scanf(" %[^\t\n]s",&newCUSTOMER.fname);
        printf("Enter Last Name: ");
        scanf(" %[^\t\n]s",&newCUSTOMER.lname);
        printf("Enter Business Name: ");
        scanf(" %[^\t\n]s",&newCUSTOMER.bname);
        printf("Enter Street Address: ");
        scanf(" %[^\t\n]s",&newCUSTOMER.sadd);
        printf("Enter Town: ");
        scanf(" %[^\t\n]s",&newCUSTOMER.town);
        printf("Enter Province: ");
        scanf(" %[^\t\n]s",&newCUSTOMER.province);
        printf("Enter Postal Code: ");
        scanf(" %[^\t\n]s",&newCUSTOMER.postalcode);
        printf("Enter Phone Number: ");
        scanf(" %[^\t\n]s",&newCUSTOMER.phonenumber);
        // Store customer data into the binary file
        fseek(customer_file,newCUSTOMER.cid*sizeof(struct customer), SEEK_SET);
        fwrite(&newCUSTOMER,sizeof(struct customer),1,customer_file);
        fclose(customer_file);
        newCUSTOMER.cid++;
        open_files();
    }
    else
    	printf("Invalid Entry.\n\n");
    return 0;
}
#endif
