#include<iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "md5.h"
using namespace std;
int main(int argc, char *argv[])
{
    if(argc == 1)
        cout<<"Need argvument\n";
    int fd = open(argv[1],O_RDONLY);
    cout<<MD5(fd);
    return 0;
}
