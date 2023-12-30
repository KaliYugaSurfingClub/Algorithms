#include <stdio.h>
 
int main()
{
    int n;
    scanf("%d ", &n);
 
    int first_arr[n];
    int second_arr[n];
    int res_arr[n];
 
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &first_arr[i]);
    }
        for (int i = 0; i < n; i++)
    {
        scanf("%d ", &second_arr[i]);
    }
 
    for (int i = 0; i < n; i++)
    {
        if (first_arr[i] < second_arr[i])
        {
            res_arr[i] = first_arr[i];
        }
        else
        {
            res_arr[i] = second_arr[i];
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        printf("%d ", res_arr[i]);
    }
 
    return 0;
}