#include <stdio.h>
#define MAX 21

int cache[MAX][MAX][MAX];
int cache_flag[MAX][MAX][MAX];


int f(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20)
    {
        return f(20, 20, 20);
    }
    
    if(a < b && b < c)
    {
        if (!cache_flag[a][b][c])
        {
            cache[a][b][c] = f(a, b, c-1) + f(a, b-1, c-1) - f(a, b-1, c);
            cache_flag[a][b][c] = 1;
        }

        return cache[a][b][c];
    }

    if (!cache_flag[a][b][c])
    {
        cache[a][b][c] = f(a-1, b, c) + f(a-1, b-1, c) + f(a-1, b, c-1) - f(a-1, b-1, c-1);
        cache_flag[a][b][c] = 1;
    }

    return cache[a][b][c];
}


int main()
{
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; j < MAX; j++)
        {
            for (int k = 1; k < MAX; k++)
            {
                cache_flag[i][j][k] = 0;
            }
        }
    }

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("%d", f(a, b, c));

    return 0;
}
