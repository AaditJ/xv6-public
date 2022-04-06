#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "mmu.h"

int main(int argc,char *argv[])
{

    int str;
    str = (int )sbrk(0);
    
    printf(1,"%d\n", str);
    int len = 1;


    mprotect((void *)str, len);
    exit();
}