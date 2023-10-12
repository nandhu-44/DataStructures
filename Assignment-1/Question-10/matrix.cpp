// Write a program to read and print a matrix of size m x n. Also find the row sum and the column sum, and print the column number and row number that has the largest sum. Keep your code modular.

#include <iostream>
using namespace std;

// Module to set matrix.
void setMatrix(int **matrix, int m, int n)
{
    cout << "Enter elements of matrix" << endl;
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "] : ";
            cin >> matrix[i][j];
        }
    }
}

// Module to print matrix.
void printMatrix(int **matrix, int m, int n)
{
    cout << "Matrix is : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Module to find row sum.
void rowSum(int **matrix, int m, int n)
{
    int sum = 0;
    int row = 0;
    for (int i = 0; i < m; i++) // using row for iteration
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            temp += matrix[i][j]; // Adding elements of each row.
        }
        if (temp > sum)
        {
            sum = temp;
            row = i;
        }
    }
    cout << "Row " << row + 1 << " has the largest sum of " << sum << endl;
}

// Module to find column sum.
void columnSum(int **matrix, int m, int n)
{
    int sum = 0;
    int column = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < m; j++) // using column for iteration
        {
            temp += matrix[j][i]; // Adding elements of each column.
        }
        if (temp > sum)
        {
            sum = temp;
            column = i;
        }
    }
    cout << "Column " << column + 1 << " has the largest sum of " << sum << endl;
}

int main()
{
    int m, n;
    cout << "Enter the number of rows : ";
    cin >> m;
    cout << "Enter the number of columns : ";
    cin >> n;
    if (m <= 0 || n <= 0)
    {
        cout << "Invalid input!" << endl;
        return 1;
    }
    int **matrix = new int *[m];
    setMatrix(matrix, m, n); // Calling module to set matrix.
    cout << endl;
    printMatrix(matrix, m, n); // Calling module to print matrix.
    cout << endl;
    rowSum(matrix, m, n); // Calling module to find row sum.
    cout << endl;
    columnSum(matrix, m, n); // Calling module to find column sum.
    return 0;
}

/**
 * ___Output___
Enter the number of rows : 2
Enter the number of columns : 2
Enter elements of matrix
Enter element [1][1] : 1
Enter element [1][2] : 8
Enter element [2][1] : 4
Enter element [2][2] : 0

Matrix is :
1       8
4       0

Row 1 has largest sum : 9

Column 2 has largest sum : 8
*/