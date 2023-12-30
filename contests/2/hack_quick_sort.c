#include <stdio.h>

void read_arr(int *arr, int len);
void print_arr(int *arr, int len);
void hack_sort(int *iterations, int count, int *res);
int count_of_zeros(int *arr, int len);
int get_index_numbered_zero(int *arr, int len, int number);


int main()
{  
    int iterations_count;

    scanf("%d", &iterations_count);
    int iterations[iterations_count];
    int res[iterations_count];
    
    read_arr(iterations, iterations_count);

    hack_sort(iterations, iterations_count, res);

    print_arr(res, iterations_count);
}


void hack_sort(int *iterations, int count, int *res)
{
    for (int i = 0; i < count; i++)
    {
        res[i] = 0;
    }

    int current_element = count;

    for (int i = 0; i < count; i++)
    {
        if (iterations[i] == 0)
        {
            int zero_count = count_of_zeros(res, count);
            int middle_index = (zero_count - 1) / 2;
            int index = get_index_numbered_zero(res, count, middle_index + 1);
            res[index] = current_element--;
        }

        if (iterations[i] == 1)
        {
            for (int j = 0; j < count; j++)
            {   
                if (res[j] == 0)
                {
                    res[j] = current_element--;
                    break;
                }
            }
        }

        if (iterations[i] == -1)
        {
            for (int j = count - 1; j >= 0; j--)
            {   
                if (res[j] == 0)
                {
                    res[j] = current_element--;
                    break;
                }
            }
        }
    }
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


int count_of_zeros(int *arr, int len)
{
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 0)
        {
            res++;
        }
    }
    return res;
}


int get_index_numbered_zero(int *arr, int len, int number)
{
    int count_of_zeros = 0;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 0)
        {
            count_of_zeros++;
        }
        if (count_of_zeros == number)
        {
            return i;
        }
    }

    return -1;
}