#ifndef Get_Supplier_Data
#define Get_Supplier_Data

#include "header.h"

// Function to read supplier data from a text file and store it in a binary file
int get_supplier_data(void)
{
    // Declear files values
    int option,x;
    char file_name[30], input_buffer[1000],password[100];
    char c;
    //Prompting user to select whether to input via a whole file or enter a singular data
    printf("\nSelect one of the following: \n");
    printf("1: Add multiple suppliers by file\n");
    printf("2: Add a singular supplier\n");
    printf("0: Main Menu\n");
    printf("\nOption #: ");
    scanf("%d",&option);
    
    //If the user wants to enter from a file
    if(option==1)
    {
	    x=0;
        printf("\n -- Secure Access --\nEnter password: ");
        scanf("%s",password);
        if(strcmp(password,"password")==0)
        {
	    //Prompting user to type in a file name
	    printf("Enter name of file to read: ");
	    scanf("%s",file_name);
	             
	    //Opening input file
        if(fopen(file_name,"r")==NULL)
        {
            printf("\nInvalid File name. Please try again.\n");
            return 0;
        }
	    input_file=fopen(file_name,"r");
	                
	    //Reading data into buffer
	    while(fgets(input_buffer, 1000, input_file)>0)
	    {      
	    //Ignoring first line because its the title
	    if(x==0)
	    	x++;           
	    //Other lines except first
	    else
	    {            
		    //Storing data into supplier struct
		    sscanf(input_buffer,"%[^\t]%*c %[^\t]%*c %[^\t]%*c \"%100[^\"]\" %[^\t]%*c %[^\t]%*c",&newSUPPLIER.mname, &newSUPPLIER.name,&newSUPPLIER.cname,&newSUPPLIER.sadd,&newSUPPLIER.phonenumber,&newSUPPLIER.email);
		                   
		    //Store Supplier data into binary file
		    fseek(supplier_file,newSUPPLIER.sid*sizeof(struct supplier), SEEK_SET);
		    fwrite(&newSUPPLIER,sizeof(struct supplier),1,supplier_file);
		                    
		    //Incrementing ID counter
		    newSUPPLIER.sid++;
            
            fclose(supplier_file);
            open_files();
	    }
	    }
        }else{
            printf("\nIncorrect Password. Please try again.\n");
        }
	}
    //If user wants to enter supplier data manually
    else if(option==2)
    {
        while((fread(&newSUPPLIER, sizeof(newSUPPLIER), 1, supplier_file))>0)
        {
            newSUPPLIER.sid++;
        }
	    //Promting user to enter supplier data
	    printf("\nSupplier ID: %d",newSUPPLIER.sid);
	    printf("\nEnter Manufacturer Name: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.mname);
	    printf("Enter Contact Name: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.name);
	    printf("Enter Company Name: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.cname);
	    printf("Enter Address: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.sadd);
	    printf("Enter Phone Number: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.phonenumber);
	    printf("Enter Email address: ");
	    scanf(" %[^\t\n]s",&newSUPPLIER.email);
	                
	    //Store Supplier data into binary file
	    fseek(supplier_file,newSUPPLIER.sid*sizeof(struct supplier), SEEK_SET);
	    fwrite(&newSUPPLIER,sizeof(struct supplier),1,supplier_file);
        newSUPPLIER.sid++;
        fclose(supplier_file);
        open_files();
    }
    
    //Hotkey to exit function
    else if(option==0)
    {
        return 0;
    }
    //When an unrecognized value is entered
    else
    {
    	printf("Invalid Entry.\n\n");
	}

    //Returning values
    return 0;
}

#endif
