#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXBIN 100

void reverse(char *s)
{
    int bf;
    unsigned long long len = 0;
    while (s[len]) len++;

    for (unsigned long long i = 0; i < len / 2; i++) 
    {
        bf = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = bf;
    }
}

void revers_rec(unsigned long long number)
{
    static char res[MAXBIN];
    static unsigned long long index = 0;
    static int last_c = '\0';
    static int flag = OUT;

    if (number == 0)
    {
        res[index] = '\0';
        printf("%s\n", res);
        return;
    }

    char new_c = number % 2 + '0';
    if (last_c != new_c || flag == OUT)
    {
        res[index++] = new_c;
        flag = IN;
    }
    else 
    {
        flag = OUT;
    }

    last_c = new_c;
    revers_rec(number / 2);
}


void straight_rec(unsigned long long number)
{
    static char res[MAXBIN];
    static int index = 0;
    static int flag = IN;

    if (number == 0)
    {
        res[index] = '\0';
        reverse(res);
        printf("%s\n", res);
        return;
    }

    char next_c = (number / 2) % 2 + '0';
    char new_c = number % 2 + '0';

    if (new_c != next_c || flag == OUT || number / 2 == 0)
    {
        res[index++] = new_c;
        flag = IN;
    }
    else 
    {
        flag = OUT;
    }

    straight_rec(number / 2);    
}


void m_rec(unsigned long long number)
{
    straight_rec(number);
    revers_rec(number);
}


int main()
{
    unsigned long long number = 0;
    scanf("%lld", &number);

    m_rec(number);

    return 0;
}