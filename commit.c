#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include <sys/stat.h>
char rem[100][1000];char buff[1000];
int counter = 0;
void word(char *a, int n,char *b)
{
    int space[100],k=1,i;char ret[1000];
    space[0] = -1;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == ' ')
        {
            space[k++] = i;
        }
    }
    k = 0;
    for (i = space[n - 1] + 1; a[i] != '\0' && i != space[n]; i++)
        b[k++] = a[i];
    ret[k] = '\0';
    return;
}

void hashb(char *a,char *b)
{
    char str[2500];
    FILE *fi;
    fi = fopen(a, "r");
    while (fgets(str, 256, fi));
    fclose(fi);
    SHA_CTX ctx;
    SHA1_Init(&ctx);
    SHA1_Update(&ctx, str, strlen(str));
    unsigned char tmphash[SHA_DIGEST_LENGTH];
    SHA1_Final(tmphash, &ctx);
    int i = 0;
    for (i = 0; i < SHA_DIGEST_LENGTH; i++)
    {
        sprintf((char *)&(b[i * 2]), "%02x", tmphash[i]);
    }
    return;
}

void fakehashb(char *a,char *b)
{   SHA_CTX ctx;
    SHA1_Init(&ctx);
    SHA1_Update(&ctx, a, strlen(a));
    unsigned char tmphash[SHA_DIGEST_LENGTH];
    SHA1_Final(tmphash, &ctx);
    int i = 0;
    for (i = 0; i < SHA_DIGEST_LENGTH; i++)
    {
        sprintf((char *)&(b[i * 2]), "%02x", tmphash[i]);
    }
    strcpy(rem[counter++],b);
    return ;
}

int depth(char *a)
{
    int j = 0;
    if(strlen(a)==0) return -1;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '/')
            j++;
    }
    return j;
}

void separate(char *a, char *b)
{
    int i = strlen(a) - 1, k = 0;
    while (a[i] != '/' && i > -1)
        i--;
    if (i > -1)
    {
        a[i] = '\0';
        i++;
        for (i; a[i] != '\0'; i++)
            b[k++] = a[i];
        b[k] = '\0';
        return;
    }
    strcpy(b, a);
    a[0] = '\0';
}

void addtree(char *a,char*b,char*c)
{FILE* test=fopen(c,"a+");char save[100],tree[100];
sprintf(tree,"tree %s %s",a,b);
int flag=0;
while(fgets(save,99,test))
{save[strlen(save)-1]='\0';
if(strcmp(save,tree)==0)
flag=-1;
}
if(flag==0)
fprintf(test,"%s\n",tree);
fclose(test);
return;}

int main(int argv,char **argc)
{   struct stat check;
    FILE *x = fopen(".xing/index", "r+"), *y;
    char m[3000], hash[10000][200], string[10000][200], tail[10000][200], fakehash[10000][200],a[1000];
    int i = 0, count = 0, d[1000], maxd = 0, file[1000];
    while (fgets(m, 100, x))
    {
        word(m, 1,hash[i]);
        word(m, 2,string[i]);
        d[i] = depth(string[i]);
        if (maxd < d[i])
            maxd = d[i];
        file[i] = 1;
        i++;
    }
    count = i;
    for (i = 0; i < count; i++)
    {
        separate(string[i], tail[i]);
        fakehashb(string[i],fakehash[i]);
        y = fopen(fakehash[i], "a");
        fprintf(y, "node %s %s", hash[i], tail[i]);
        fclose(y);
       }
    fclose(x);
    for (i = 0; i < count; i++)
        if (d[i] == maxd)
        {   file[i] = 0;
            hashb(fakehash[i],hash[i]);
            if(stat(hash[i],&check)!=0)
               {       FILE * read=fopen(fakehash[i],"r"),*write=fopen(hash[i],"w");
         while(fgets(a,500,read))
            fputs(a,write);
            fclose(read);fclose(write);}
            }

    while (maxd)
    {
        for (i = 0; i < count; i++)
        {
            if (d[i] == maxd && file[i] == 0)
            {
                separate(string[i], tail[i]);
                fakehashb(string[i],fakehash[i]);
             addtree(hash[i],tail[i],fakehash[i]);
             //sprintf(m, "/home/drake/xing/commit.sh %s %s %s", hash[i], tail[i], fakehash[i]);
             //system(m);
        }}

        for (i = 0; i < count; i++)
        {
            if (d[i] == maxd)
            {  hashb(fakehash[i],hash[i]);         
            if(stat(hash[i],&check)!=0)//if hash doesn't exist create it otherwise don't.
               {FILE * read=fopen(fakehash[i],"r"),*write=fopen(hash[i],"w");
         while(fgets(a,500,read))//
            fputs(a,write);
            fclose(read);fclose(write);}
                d[i]--;
                file[i] = 0;
             if(strlen(string[i])==0)
            {
             FILE *commit=fopen("comm","a+");
             fprintf(commit,"parent tree %s\n",hash[i]);
             fclose(commit);                      
            }
                }
        }
        maxd--;
    }
    for (int i = 0; i < counter; i++)
        remove(rem[i]);
    FILE * commit=fopen("comm","a+");
    fprintf(commit,"commit message \n%s",argc[1]);
    fclose(commit);
    return 0;
}