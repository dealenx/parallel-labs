#include "mpi.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "helper.h"

using namespace std;

int main(int argc, char *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Status stat;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {

        int n = atoi(argv[1]);

        int step = n / size;

        for (int i = 1; i < size; i++)
        {
            MPI_Send(&n, 1, MPI_INT, i, 000, MPI_COMM_WORLD);
            MPI_Send(&step, 1, MPI_INT, i, 000, MPI_COMM_WORLD);
        }

        double **A = new double *[n];

        A[0] = new double[n * n];

        for (int i = 1; i < n; i++)

            A[i] = A[i - 1] + n;

        double *b = new double[n];

        double *c = new double[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                A[i][j] = 1. / (i + j + 1);

            b[i] = 1. / (i + 1);
        }

        double time1 = MPI_Wtime();
        for (int i = 1; i < size; i++)
        {

            MPI_Send(&A[step * i][0], n * step, MPI_DOUBLE, i, 000, MPI_COMM_WORLD);
            MPI_Send(&b[0], n, MPI_DOUBLE, i, 000, MPI_COMM_WORLD);
        }

        //Ab = c
        for (int i = 0; i < step; i++)
        {
            c[i] = 0;
            for (int j = 0; j < n; j++)
                c[i] += A[i][j] * b[j];
        }

        for (int i = 1; i < size; i++)
            MPI_Recv(&c[step * i], step, MPI_DOUBLE, i, 000, MPI_COMM_WORLD, &stat);

        double time2 = MPI_Wtime();

        double time = time2 - time1;

        // printArray(c, n);

        cout << endl
             << "Time: " << time << endl;

        delete[] A[0];
        delete[] c;
        delete[] b;
    }

    if (rank != 0)
    {
        int n, step;
        MPI_Recv(&n, 1, MPI_INT, 0, 000, MPI_COMM_WORLD, &stat);
        MPI_Recv(&step, 1, MPI_INT, 0, 000, MPI_COMM_WORLD, &stat);

        double **A = new double *[n];

        A[0] = new double[n * step];
        for (int i = 1; i < step; i++)
            A[i] = A[i - 1] + n;

        double *b = new double[n];
        double *c = new double[step];

        MPI_Recv(&A[0][0], n * (step), MPI_DOUBLE, 0, 000, MPI_COMM_WORLD, &stat);
        MPI_Recv(&b[0], n, MPI_DOUBLE, 0, 000, MPI_COMM_WORLD, &stat);

        //Ab = c
        for (int i = 0; i < step; i++)
        {
            c[i] = 0;

            for (int j = 0; j < n; j++)
            {
                c[i] += A[i][j] * b[j];
            }
        }

        MPI_Send(&c[0], step, MPI_DOUBLE, 0, 000, MPI_COMM_WORLD);

        delete[] A[0];
        delete[] c;
        delete[] b;
    }

    MPI_Finalize();

    return 0;
}