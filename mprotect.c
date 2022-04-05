#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc,char *argv[])
{

    int x = 8100;
    int *str = &x;
    int len = 1;

    mprotect(str, len);
    exit();
}