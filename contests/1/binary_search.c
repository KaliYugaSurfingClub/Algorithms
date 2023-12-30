#include <stdio.h>

#define NO_TARGET -1

int history[100000000][2];
int history_count = 0;

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


void print_history()
{
    for (int i = 0; i < history_count; i++)
    {
        printf("%d(%d) ", history[i][0], history[i][1]);
    }
    putchar('\n');
}


int binary_search(int *arr, int left, int right, int target)
{
    if (left > right)
    {
        return NO_TARGET;
    }

    int index = (left + right) / 2;

    history[history_count][0] = arr[index];
    history[history_count][1] = index;
    history_count++;

    if (arr[index] == target)
    {
        return index;
    }
    else if (target > arr[index])
    {
        binary_search(arr, index + 1, right, target);
    }
    else if (target < arr[index])
    {
        binary_search(arr, left, index - 1, target);
    }
}


void print_answer(int *arr, int count, int target, int res)
{
    printf("Initial array:\n");
    print_arr(arr, count);
    printf("Target element: %d\n", target);
    printf("Search history: ");
    print_history();
    if (res == NO_TARGET)
    {
        printf("No targets");
    }
    else
    {
        printf("Target is found at: %d", res);
    }
}


int main()
{
    int count, target;
    scanf("%d %d", &count, &target);

    int arr[count];

    read_arr(arr, count);
    int res = binary_search(arr, 0, count - 1, target);
    print_answer(arr, count, target, res);

    return 0;
}