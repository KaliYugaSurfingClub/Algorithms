#include <stdio.h>
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
 
    long long matrix[n][m];
    long long row_sum_arr[n];
    long long column_sum_arr[m];
 
    for (int i = 0; i < n; i++)
    {
        row_sum_arr[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        column_sum_arr[i] = 0;
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%lld ", &matrix[i][j]);
 
            row_sum_arr[i] += matrix[i][j];
            column_sum_arr[j] += matrix[i][j];
        }
 
    }
 
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", row_sum_arr[i]);
    }
    putchar('\n');
    for (int i = 0; i < m; i++)
    {
        printf("%lld ", column_sum_arr[i]);
    }
 
 
    return 0;
}