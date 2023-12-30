#include <stdio.h>

void read_arr(int *arr, int len);
void print_arr(int *arr, int len);
void quick_sort(int *arr, int left, int right);
void swap_keeping_order(int left, int target, int *arr);


int count;

int main()
{    
    scanf("%d", &count);
    int arr[count];

    read_arr(arr, count);  

    printf("Initial array:\n");
    print_arr(arr, count);
    putchar('\n');

    quick_sort(arr, 0, count - 1);

    return 0;
}


void quick_sort(int *arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int middle_index = (left + right) / 2;
    printf("Pivot index: %d , pivot element: %d\n", middle_index, arr[middle_index]);

    swap_keeping_order(left, middle_index, arr);

    int pivot = arr[left];
    int c_index = left + 1;
    int wall = left + 1;

    while (c_index <= right)
    {
        if (arr[c_index] <= pivot)
        {
            swap_keeping_order(wall - 1, c_index, arr);
            wall++;
        }

        c_index++;
    }
    wall--;

    printf("Array after partition: ");
    print_arr(arr, count);
    putchar('\n');

    quick_sort(arr, left, wall - 1);
    quick_sort(arr, wall + 1, right);
}


void read_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        scanf("%d ", &arr[i]);
    }
}


void print_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}



void swap_keeping_order(int left, int target, int *arr)
{
    for (int i = target; i > left; i--)
    {
        int buffer = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = buffer;
    }
}
