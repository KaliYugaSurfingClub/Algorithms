#include <stdio.h>
#include <stdlib.h>

void read_arr(int *arr, int len);
void print_arr(int *arr, int len);
void swap(int *a, int *b);
void merge_sort(int *arr, int left, int right);

int count = 1;

int main()
{
    scanf("%d", &count);
    int arr[count];

    read_arr(arr, count);

    merge_sort(arr, 0, count - 1);

    print_arr(arr, count);

    return 0;
}


void merge_sort(int *arr, int left, int right)
{
    if (left == right) return;

    int middle_index = (left + right) / 2;

    merge_sort(arr, left, middle_index);
    merge_sort(arr, middle_index + 1, right);

    int i = left;  // начало первого пути
    int j = middle_index + 1; // начало второго пути
    int *tmp = (int*)malloc(right * sizeof(int)); // дополнительный массив
    for (int step = 0; step < right - left + 1; step++) // для всех элементов дополнительного массива
    {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        if ((j > right) || ((i <= middle_index) && (arr[i] < arr[j]))) 
        {
            tmp[step] = arr[i];
            i++;
        }
        else 
        {
            tmp[step] = arr[j];
            j++;
        }
        print_arr(tmp, step);
    }
    // переписываем сформированную последовательность в исходный массив
    for (int step = 0; step < right - left + 1; step++)
        arr[left + step] = tmp[step];
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


void swap(int *a, int *b)
{
    int buffer = *a;
    *a = *b;
    *b = buffer;
}
