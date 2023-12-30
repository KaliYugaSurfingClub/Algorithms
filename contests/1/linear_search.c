#include <stdio.h>


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


int liner_search(int *arr, int len, int target, int *indexes_of_target)
{
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
        {
            indexes_of_target[j++] = i;
        }
    }

    return j;
}


void print_answer(int *arr, int count, int target, int count_targets, int *indexes_of_target)
{
    printf("Initial array:\n");
    print_arr(arr, count);
    printf("Target element: %d\n", target);
    if (count_targets == 0)
    {
        printf("No targets");
    }
    else
    {
        printf("Target is found at: ");
        print_arr(indexes_of_target, count_targets);
    }
}


int main()
{
    int count, target;
    scanf("%d %d", &count, &target);

    int arr[count];
    int indexes_of_target[count];

    read_arr(arr, count);
    int count_targets = liner_search(arr, count, target, indexes_of_target);
    print_answer(arr, count, target, count_targets, indexes_of_target);

    return 0;
}