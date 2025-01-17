#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "mmu.h"

int main(int argc,char *argv[])
{
    int addr, len ,retval;
    len = 0;
    addr = 0;

    // Fail case for invalid len   
    retval = mprotect((void *)addr, len);

    if(retval == -1){
        printf(1,"Len test failed as expected, return val: %d\n", retval);
    }

    len = 2;
    addr = -1;

    // Fail case for correct len but not page aligned address
    retval = mprotect((void *)addr, len);

    if(retval == -1){
        printf(1,"Address test failed as expected, return val: %d\n", retval);
    }

    void *ptr = malloc(2*PGSIZE);

    printf(1,"Setting memory without being protected, should not throw errors\n");
    memset(ptr , 1, 2*PGSIZE);
    
    printf(1,"memset OK\n");
    
    //Protect allocated memory
    addr = PGROUNDUP((unsigned int)ptr);

    printf(1,"Protecting memory\n");

    // Success case for correctly protected memory
    retval = mprotect((void*)addr, len);
    if(retval ==0){
        printf(1,"Memory protected successfully, return val: %d\n", retval);
    };

    printf(1,"Attempting to set to protected memory, should throw error\n");  
    memset((void*)addr , 5, 2*PGSIZE);

    exit();
}