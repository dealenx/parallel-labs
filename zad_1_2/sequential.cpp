#include "mpi.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void printMatrix(double **matrix, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(14) << matrix[i][j];
        }
        cout << endl;
    }
}

void printArray(double *array, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(14) << array[i];
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    int rank, size, n;

    MPI_Init(&argc, &argv);
    MPI_Status stat;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    n = atoi(argv[1]); // Аргумент запуска программы

    double **A = new double *[n];

    for (int i = 0; i < n; i++)
        A[i] = A[i];

    double *b = new double[n];

    double *c = new double[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            A[i][j] = 1. / (i + j + 1);

        b[i] = 1. / (i + 1);
    }

    // Вывод начальных данных
    printMatrix(A, n);
    printArray(b, n);

    double time1 = MPI_Wtime();

    // A*b = c
    for (int i = 0; i < n; i++)
    {
        c[i] = 0;
        for (int j = 0; j < n; j++)
        {
            c[i] += A[i][j] * b[j];
        }
    }

    double time2 = MPI_Wtime();
    double time = time2 - time1;

    // Вывод результата
    printArray(c, n);

    cout << endl
         << "Time: " << time << endl;

    MPI_Finalize();

    return 0;
}