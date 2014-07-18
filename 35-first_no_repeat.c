#include <stdio.h>

char first_no_repeat(char *pstr)
{
    if(pstr==NULL)
        return '\0';
    const int table_size=256;
    unsigned int hash_table[table_size];
    unsigned int i;
    for(i=0;i<table_size;i++)
        hash_table[i]=0;
    char *phash_key = pstr;
    while(*(phash_key)!='\0')
        hash_table[*(phash_key++)]++;
    phash_key = pstr;
    while(*phash_key !='\0')
    {
        if(hash_table[*phash_key]==1)
            return *phash_key;
        phash_key++;
    }
    return '\0';
}

int main()
{
    char str[256];
    fgets(str,256,stdin);
    putchar(first_no_repeat(str));
    putchar('\n');
    return 0;
}
