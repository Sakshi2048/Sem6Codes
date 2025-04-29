#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (matrix[i][j] == 1 ? "Q " : "- ");
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>> &matrix, int row, int col)
{
    int n = matrix.size();

    // Check column
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][col] == 1)
            return false;
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (matrix[i][j] == 1)
            return false;
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (matrix[i][j] == 1)
            return false;
    }

    return true;
}

void placeQueen(vector<vector<int>> &matrix, int row, int &solutionCount)
{

    int n = matrix.size();

    // All Queens placed - solution found
    if (row == n)
    {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        printBoard(matrix);
        cout << endl;
        return;
    }


    for (int col = 0; col < n; col++)
    {
        // If Cell is safe to place
        if (isSafe(matrix, row, col))
        {
            // Place Queen
            matrix[row][col] = 1;

            // Place next queens
            placeQueen(matrix, row + 1, solutionCount);

            // Backtracking - if no safe place found for a queen - remove current queen
            matrix[row][col] = 0; 
        }
    }
}

void solve(int n)
{
    // Initialize board
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    // Possible no. of solutions
    int solutionCount = 0;

    placeQueen(matrix, 0, solutionCount);

    // If no solution exist
    if (solutionCount == 0)
    {
        cout << "No solution exists!" << endl;
    }
}

int main()
{

    int n;
    cout << "Total Queens: ";
    cin >> n;

    cout << endl;

    solve(n);
    
    return 0;
}
