#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *word(char *a, int n)
{
    int space[100];
    char *ret = malloc(sizeof(char) * 100);
    int k = 1, i;
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
        ret[k++] = a[i];
    ret[k] = '\0';
    return ret;
}

char *hashb(char *a)
{
    char *str = malloc(sizeof(char) * 256), read[256];
    FILE *b;
    sprintf(str, "/home/drake/xing/hash-app %s", a);
    system(str);
    b = fopen("a", "r+");
    if (!b)
    {
        return a;
    }
    fgets(str, 256, b);
    fclose(b);
    remove("a");
    return word(str, 1);
}

char *fakehashb(char *a)
{
    char *str = malloc(sizeof(char) * 256), read[256];
    FILE *b;
    sprintf(str, "echo %s > x;sha1sum x>a", a);
    system(str);
    b = fopen("a", "r+");
    fgets(str, 256, b);
    fclose(b);
    remove("a");
    remove("x");
    return word(str, 1);
}

int depth(char *a)
{
    int j = 0;
    for (int i = 0; a[i] != '\0'; i++)
        {if (a[i] == '/')
            j++;}
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
    FILE *x = fopen("index", "r+"), *y;
    char m[300], hash[1000][200], string[1000][200], tail[1000][200], fakehash[1000][200];
    int i = 0, count = 0, d[1000], maxd = 0,file[1000];
    while (fgets(m, 100, x))
    {
        strcpy(hash[i], word(m, 1));
        free(word(m, 1));
        strcpy(string[i], word(m, 2));
        free(word(m, 2));
        d[i] = depth(string[i]);
        if(maxd<d[i])maxd=d[i];
        file[i]=1;
        i++;
    }
    count = i;
    for (i = 0; i < count; i++)
        {
            separate(string[i], tail[i]);
            strcpy(fakehash[i], fakehashb(string[i]));
            y = fopen(fakehash[i], "a");
            fprintf(y, "node %s %s", hash[i], tail[i]);
            fclose(y);
        }
    for (i = 0; i < count; i++)
        if (d[i] == maxd)
        {   file[i]=0;
            sprintf(m,"cp %s %s",fakehash[i],hashb(fakehash[i]));
             system(m); strcpy(hash[i], hashb(fakehash[i]));

        }

    while (maxd)
    {
        for (i = 0; i < count; i++)
        {
            if (d[i] == maxd && file[i]==0)
            {   separate(string[i], tail[i]);
                strcpy(fakehash[i], fakehashb(string[i]));
                sprintf(m,"/home/drake/xing/commit.sh %s %s %s",hash[i],tail[i],fakehash[i]);
                system(m);
            }
        }

        for (i = 0; i < count; i++)
        {
            if (d[i] == maxd)
            {sprintf(m,"cp %s %s",fakehash[i],hashb(fakehash[i]));
             system(m);
            strcpy(hash[i], hashb(fakehash[i]));   
                d[i]--;file[i]=0;
            }
        }
        maxd--;
    }
    return 0;
}