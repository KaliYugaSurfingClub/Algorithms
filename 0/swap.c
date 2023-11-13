#include <stdio.h>
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
 
    int arr[n]; 
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }
 
    for (int i = 0; i < m; i++)
    {
        int first_index, secont_index;
        scanf("%d %d", &first_index, &secont_index);
        
        int buffer = arr[first_index];
        arr[first_index] = arr[secont_index];
        arr[secont_index] = buffer;
    }
 
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
 
    return 0;
}