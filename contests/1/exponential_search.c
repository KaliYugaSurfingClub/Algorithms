#include <stdio.h>

#define NO_TARGET -1

enum {
    SEARCH, BOUND
};

int history[10000000][3];
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


void print_history(int type)
{
    int i;
    for (i = 0; history[i][2] != type; i++);
    
    if (i == history_count)
    {
        return;
    }


    printf("%s history: ", (type == SEARCH) ? "Search" : "Bounds");
    for (int i = 0; i < history_count; i++)
    {
        if (history[i][2] == type)
        {
            printf("%d(%d) ", history[i][0], history[i][1]);
        }
    }
    putchar('\n');
}


void add_history_element(int element, int index, int type)
{
    history[history_count][0] = element;
    history[history_count][1] = index;
    history[history_count][2] = type;
    history_count++;
}


int binary_search(int *arr, int left, int right, int target)
{
    if (left > right)
    {
        return NO_TARGET;
    }

    int index = (left + right) / 2;
    add_history_element(arr[index], index, SEARCH);

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


int exponential_search(int *arr, int len, int target)
{
    add_history_element(arr[0], 0, BOUND);
    if (arr[0] == target)
    {
        return 0;
    }

    if (arr[0] > target)
    {
        return NO_TARGET;
    }

    int i;
    for (i = 1; i < len && arr[i] <= target; i *= 2)
    {
        add_history_element(arr[i], i, BOUND);

        if (arr[i] == target)
        {
            return i;
        }
    }

    if (arr[len - 1] > target && i < len)
    {
        add_history_element(arr[i], i, BOUND);
    }
    

    int left = i / 2 + 1;
    int right = (i >= len) ? len - 1 : i - 1;

    return binary_search(arr, left, right, target);
}


void print_answer(int *arr, int count, int target, int res)
{
    printf("Initial array:\n");
    print_arr(arr, count);
    printf("Target element: %d\n", target);
    print_history(BOUND);
    print_history(SEARCH);
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
    int res = exponential_search(arr, count, target);
    print_answer(arr, count, target, res);

    return 0;
}