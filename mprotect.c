#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "mmu.h"



int main(int argc,char *argv[])
{

    int str, len ,retval;
    len = 0;
    str = 0;
    
    retval = mprotect((void *)str, len);

    if(retval!= -1){
        printf(1,"Len test failed, return val: %d\n", retval);
    }

    len = 1;
    str = -1;

    retval = mprotect((void *)str, len);

    if(retval!= -1){
        printf(1,"Len test failed, return val: %d\n", retval);
    }

    // This value stores the address
    str = (int )0x10000000 + PGSIZE + PGSIZE;
    // To write to this address, what would we have to do? pde = &pgdir[PDX(va)]; - This should be able to get right address where va = str
    // pde_t* pde = &(myproc()->pgdir)[PDX(str)];

    //printf(1,"%d\n", str);
    str = (uint) str;

    //Normal case-should pass appropriately
    mprotect((void *)str, len);
    
    memset((void *)0x8dfbc004 + PGSIZE, 1, PGSIZE);

    exit();
}