#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> matrix, int n, int m, string s)
{
    // Print the resulting matrix
    cout << s << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void brute_force_solution(vector<vector<int>> matrix)
{
    // Summary:
    // This solution sets all elements in rows and columns containing at least one 0 to 0.
    // It achieves this by marking rows and columns to be zeroed out and then zeroing them out in the matrix.

    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    // Mark rows and columns to be zeroed
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Zero out the marked rows and columns
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    print(matrix, n, m, "Brute Force Solution:");
}

void optimal_solution(vector<vector<int>> &matrix)
{
    // Summary:
    // This solution sets all works as the same case but here the rows an cols are not taken seperately but taken itside the array
    // itself and iterated from the backside.

    // The col[m] is matrix[0][...]
    // The row[n] is matrix[...][0]

    int col0 = 1;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for col and row
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }

    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }
    print(matrix, n, m, "Optimal Approach Solution:");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Vector matrix
    vector<vector<int>> matrix{
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};

    // Printing the Input
    print(matrix, matrix.size(), matrix[0].size(), "Input:");

    // Brute Force Solution
    brute_force_solution(matrix);

    // Optimal Solution
    optimal_solution(matrix);
}
