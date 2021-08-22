#include<stdio.h>
#include<string.h>
#include<errno.h>
#include <stdbool.h>
#define GRN  "\x1B[32m"
#define RED  "\x1B[31m"
int main(int argc,char ** argv)
{   FILE *file1,*file2;int errno;char * err;
 file1=fopen(argv[1],"r");
 err=strerror(errno);
 file2=fopen(argv[2],"r");
 err=strerror(errno);
 if(strcmp(err,"Success")!=0)
 fprintf(stderr,"%s\n",err);
    char buff1[1000],buff2[1000];
    long inscount=0,delcount=0;
    bool read1 = true, read2 = true;
    while(read1 || read2) {
        if (read1) {
            fgets(buff1,1000,file1);
            if (feof(file1)) {
                read1 = false;
            }
        }
        if (read2) {
            fgets(buff2,1000,file2);
            if (feof(file2)) {
                read2 = false;
            }
        }
        if (read1 && read2) {
            if(strcmp(buff1,buff2)!=0)
            {
                printf("%s--%s",RED,buff1);
                inscount++;
                printf("%s++%s",GRN,buff2);
                delcount++;
            }
        } else if (read1) {
            printf("%s--%s",RED,buff1);
            delcount++;
        } else if (read2) {
            printf("%s++%s",GRN,buff2);
            inscount++;
        }
    }

    fclose(file1);
    fclose(file2);
    printf("%s%ld insertions,%s%ld  deletions",GRN,inscount,RED,delcount);
    return 0;
}