#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>
char rem[100][1000];
counter = 0;
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
    unsigned char *hash = malloc(sizeof(char) * SHA_DIGEST_LENGTH * 2);
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

int main()
{
    FILE *x = fopen(".xing/index", "r+"), *y;
    char m[3000], hash[10000][200], string[10000][200], tail[10000][200], fakehash[10000][200];
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

    for (i = 0; i < count; i++)
        if (d[i] == maxd)
        {
            file[i] = 0;
            hashb(fakehash[i],hash[i]);
            sprintf(m, "cp %s %s", fakehash[i], hash[i]);
            system(m);
        }

    while (maxd)
    {
        for (i = 0; i < count; i++)
        {
            if (d[i] == maxd && file[i] == 0)
            {
                separate(string[i], tail[i]);
                fakehashb(string[i],fakehash[i]);
                sprintf(m, "/home/drake/xing/commit.sh %s %s %s", hash[i], tail[i], fakehash[i]);
                system(m);
                }
        }

        for (i = 0; i < count; i++)
        {
            if (d[i] == maxd)
            {  hashb(fakehash[i],hash[i]);
                sprintf(m, "cp %s %s", fakehash[i],hash[i]);
                system(m);
                d[i]--;
                file[i] = 0;
                }
        }
        maxd--;
    }
    for (int i = 0; i < counter; i++)
        remove(rem[i]);
    return 0;
}