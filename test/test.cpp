#include "md5.h"
#include <iostream>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    int fd = open(argv[1],O_RDONLY);
    char * m = NULL;
    m = MD5(fd);
    std::cout<<m;
    return 0;
}
