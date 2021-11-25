#ifndef Get_Supplier_Record
#define Get_Supplier_Record

#include "header.h"

int get_supplier_record(void)
{
    int rc=1;
    int rec_no=0;
    
    fseek(supplier_file, 1000 * sizeof(newSUPPLIER), SEEK_SET);
    
    while(rc>0)
    {
    	fseek(supplier_file, rec_no * sizeof(newSUPPLIER), SEEK_SET);
    	rc=fread(&newSUPPLIER, sizeof(newSUPPLIER), 1, supplier_file);
        rec_no++;
    	if(strcmp(newSUPPLIER.mname,newPRODUCTS.mname)==0)
    	{
        	return 1;
    	}
    }
    return 0;
}

#endif
