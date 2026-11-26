#include <stdio.h>
#define N 7
#define M 7

int A[M][N] = {
    {70, 60, 50, 40, 30, 20, 10},
    {10, 20, 30, 40, 50, 60, 70},
    {42, 15, 89,  7, 63, 28, 51},
    {30, 50, 30, 10, 50, 30, 10},
    {-15, 0, -40, 25, -5, 0, -100},
    { 7,  7,  7,  7,  7,  7,  7},
    {60, 50, 40, 30, 20, 10, 99}
};

void sort_row(int *arr, int *comparisons, int *shifts)
{
    int last_sorted_indx = 0;
    *comparisons = 0;
    *shifts = 0;
    while (last_sorted_indx < N - 1)
    {
        int l = 0;
        int r = last_sorted_indx;
        int key = arr[last_sorted_indx + 1];
        while (r >= l)
        {
            int m = (r + l) / 2;
            (*comparisons)++;
            if (key > arr[m])
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        for (int i = last_sorted_indx; i >= l; i--)
        {
            arr[i + 1] = arr[i];
            (*shifts)++;
        }
        arr[l] = key;
        last_sorted_indx++;
    }
}

void print_matrix(int matrix[M][N])
{
    for (int row = 0; row < M; row++)
    {
        for (int number = 0; number < N; number++)
        {
            printf("%-5d", matrix[row][number]);
        }
        printf("\n");
    }
    printf("-----------------------------------\n");
}

int main()
{
    int comparisons[M];
    int shifts[M];

    printf("-----------------------------------\n");
    printf("Before sorting:\n\n");
    print_matrix(A);

    for (int row = 0; row < M; row++)
    {
        sort_row(A[row], &comparisons[row], &shifts[row]);
    }

    printf("After sorting:\n\n");
    print_matrix(A);

    printf("Statistics:\n\n");
    printf("%-6s %-13s %-8s\n", "Row", "Comparisons", "Shifts");
    for (int row = 0; row < M; row++)
    {
        printf("%-6d %-13d %-8d\n", row, comparisons[row], shifts[row]);
    }
    return 0;
}