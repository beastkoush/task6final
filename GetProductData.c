#ifndef Get_Product_Data
#define Get_Product_Data

#include "header.h"

int get_product_data(void)
{
	//initialize variables
	int option, x;
    char file_name[50], input_buffer[1000], temp[100], password[100];
	//Prompt user for input between adding data from file or manually
    printf("\nSelect one of the following: \n");					
    printf("1: Add multiple products by file\n");
    printf("2: Add a singular product\n");
    printf("0: Main Menu\n");
    printf("\nOption #: ");
    scanf("%d",&option);
    
    //if statement for adding by file    
    if(option==1)													
    {
        x=0;
        printf("\n -- Secure Access --\nEnter password: ");
        scanf("%s",password);
        if(strcmp(password,"password")==0)
        {
		//prompt user for input file name
        printf("Enter name of file to read: ");						
        scanf("%s",file_name);
    
        if(fopen(file_name,"r")==NULL)
        {
            printf("\nInvalid File name. Please try again.\n");
            return 0;
        }
		input_file=fopen(file_name,"r");
        
	//read data into the buffer
    while(fgets(input_buffer, 1000, input_file)>0)					
    {
    	//Ignoring first line because its the title
        if(x==0)
		{
			x++;												
		}														
        else {
		//stores data into the respective structs
        sscanf(input_buffer,"%[^\t]%*c %[^\t]%*c %[^\t]%*c $%[^\t]%*c %[^\t]%*c %[^\t]%*c",&newPRODUCTS.name, &newPRODUCTS.classification,&newPRODUCTS.mname,&temp,&newPRODUCTS.mc,&newPRODUCTS.is);
  //          printf("\nTEMPCOST: %s\n",temp);
            if(temp[1]==',')
            for(int i=1;i<=strlen(temp);i++)
                 temp[i]=temp[i+1];
            newPRODUCTS.uc=strtof(temp, NULL);
     //       printf("\nCOST: %.2f\n",newPRODUCTS.uc);
        newPRODUCTS.pid++;
           
		//store data into binary file	
        fseek(product_file,newPRODUCTS.pid*sizeof(struct products), SEEK_SET);		
        fwrite(&newPRODUCTS,sizeof(struct products),1,product_file);
            
        fclose(product_file);
        open_files();
        }
    }
    }else{
        printf("\nIncorrect Password. Please try again.\n");
    }
	}
    else if(option==2)											
    {
        while((fread(&newPRODUCTS, sizeof(newPRODUCTS), 1, product_file))>0)
        {
            newPRODUCTS.pid++;
        }
		// Prompts user for input if data is added manually
	    printf("\nProduct ID: %d",newPRODUCTS.pid);
	    printf("\nEnter Product Name: ");
	    scanf(" %[^\t\n]s",&newPRODUCTS.name);
	    printf("Enter Classification: ");
	    scanf(" %[^\t\n]s",&newPRODUCTS.classification);
	    printf("Enter Manufacturer Name: ");
	    scanf(" %[^\t\n]s",&newPRODUCTS.mname);
	    printf("Enter Unit Cost: $");
	    scanf(" %f",&newPRODUCTS.uc);
	    printf("Enter Manufacturer Code: ");
	    scanf(" %[^\t\n]s",&newPRODUCTS.mc);
	    printf("Enter no of items in stock: ");
	    scanf(" %[^\t\n]s",&newPRODUCTS.is);
	        
	    //Store product data into binary file
	    fseek(product_file,newPRODUCTS.pid*sizeof(struct products), SEEK_SET);
	    fwrite(&newPRODUCTS,sizeof(struct products),1,product_file);
        
        fclose(product_file);
        open_files();
        newSUPPLIER.sid++;
    }
    //Hotkey to exit function
	else if (option == 0)
    {
    	return 0; 
	} 
	else
	{
		//unrecognized value will return invalid
        printf("Invalid Entry.\n\n");	
	}
																
	return 0;    
}
#endif
