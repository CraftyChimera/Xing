#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    int fd;char a[200]
;    umask(0);
    fd = open(argv[1], O_RDONLY, 0777);
    read(fd,a,40);
    printf("%s", a);
    return 0;
}