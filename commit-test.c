#include<stdio.h>
#include<openssl/sha.h>
#include<string.h>
int depth(char *a)
{
    int j = 1;
    if(strlen(a)==0) return 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '/')
            j++;
    }
    return j;
}

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
int main()
{ char m[3000],string[10000][200],hash[10000][200];int maxd,d[1000],file[1000],i;
FILE *x = fopen(".xing/index", "r+");
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
}