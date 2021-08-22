#include<stdio.h>
#include<string.h>
#include<errno.h>
int main(int argc,char** argv) 
{FILE* p;char c;int errno;
p=fopen(argv[1],"r+");
perror("fopen");
while(!feof(p))
{c=fgetc(p);
fputc(c,stdout);
}
return 0;
}