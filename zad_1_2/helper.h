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