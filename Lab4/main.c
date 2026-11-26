#include <stdio.h>
#include "all_matrix.h"


typedef struct Coords
{
    int x, y;
    double data;
} coords;

coords check_first_row(double matrix[M][N])
{
    coords data = {
        .x = -1,
        .y = -1,
        .data = -1.0,
    };
    int l = 0, r = N - 1, m = 0;
    while (l < r)
    {
        m = (r + l) / 2;
        if (matrix[0][m] > 5)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    if (matrix[0][r] >= 0 && matrix[0][r] <= 5)
    {
        data.x = r;
        data.y = 0;
        data.data = matrix[data.y][data.x];
    }
    return data;
}

coords check_last_col(double matrix[M][N])
{
    int l = 0, r = M - 1;
    int m;
    coords data = {-1, -1, -1};
    while (l < r)
    {
        m = (l + r) / 2;
        if (matrix[m][N - 1] > 5)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    if (matrix[r][N - 1] >= 0 && matrix[r][N - 1] <= 5)
    {
        data.x = N - 1;
        data.y = r;
        data.data = matrix[data.y][data.x];
    }
    return data;
}


void check_and_print_coords(coords *data)
{
    if (data->x == -1 || data->y == -1)
    {
        printf("Range between 0 and 5 not found\n");
    }
    else
    {
        printf("Find data: %.1lf.\nCoords:\n  Row: %d\n  Column: %d\n(%d %d)\n", data->data, data->y, data->x, data->y, data->x);
    }
}

void print_matrix(double matrix[M][N])
{
    printf("Our matrix:\n\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%+5.1lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void one_test(double matrix[M][N])
{
    print_matrix(matrix);
    coords row_data = check_first_row(matrix);
    printf("Coords for first row:\n");
    check_and_print_coords(&row_data);
    coords col_data = check_last_col(matrix);
    printf("Coords for last col:\n");
    check_and_print_coords(&col_data);
}

int main()
{
    one_test(A1);
    one_test(A2);
    one_test(A3);
    one_test(A4);
    one_test(A5);
    one_test(A6);
    one_test(A7);
    one_test(A8);
    return 0;
}