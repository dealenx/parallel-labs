#include "mpi.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int rank, size, i;
    int buffer[10];
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (size < 2)
    {
        printf("Please run with two processes.\n");
        fflush(stdout);
        MPI_Finalize();
        return 0;
    }
    if (rank == 0)
    {
        for (i = 0; i < 10; i++)
            buffer[i] = i;
        MPI_Send(buffer, 5, MPI_INT, 1, 123, MPI_COMM_WORLD);

        cout << endl;
        for (i = 0; i < 10; i++)
            cout << buffer[i] << " ";
    }
    if (rank == 1)
    {

        MPI_Recv(buffer, 5, MPI_INT, 0, 123, MPI_COMM_WORLD, &status);

        for (i = 5; i < 10; i++)
            buffer[i] = -1;

        cout << endl;
        for (i = 0; i < 10; i++)
            cout << buffer[i] << " | ";
        fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}