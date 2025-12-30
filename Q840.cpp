/*A 3 × 3 magic square is a 3 × 3 grid filled with distinct numbers from 1 to 9 such that each row, each column, and both diagonals all have the same sum.
You are given a row × col grid of integers.
Return how many 3 × 3 magic square subgrids are inside the grid.
Note:
A magic square can only contain numbers from 1 to 9
The given grid may contain numbers up to 15
Example 1

Input: grid = [[4,3,8,4],
               [9,5,1,9],
               [2,7,6,2]]
Output: 1
Explanation: The following subgrid is a magic square:
4 3 8
9 5 1
2 7 6
while this one is not:
3 8 4
9 1 9
2 7 6
In total, there is only one magic square inside the given grid.
Example 2
Input: grid = [[8]]
Output: 1
Explanation: The whole grid is a magic square, so we return 1.
Constraints
row == grid.length
col == grid[i].length
1 ≤ row, col ≤ 10
0 ≤ grid[i][j] ≤ 15
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // If grid is smaller than 3x3, no magic square possible
        if (rows < 3 || cols < 3)
            return 0;

        // Traverse all possible 3x3 subgrids
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {

                // Center of a 3x3 magic square must be 5
                if (grid[i + 1][j + 1] != 5)
                    continue;

                vector<bool> used(10, false);
                bool valid = true;

                // Check numbers are 1 to 9 and distinct
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        int val = grid[x][y];
                        if (val < 1 || val > 9 || used[val]) {
                            valid = false;
                            break;
                        }
                        used[val] = true;
                    }
                    if (!valid) break;
                }

                if (!valid) continue;

                // Sum of first row
                int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];

                // Check rows
                for (int x = i; x < i + 3; x++) {
                    int rowSum = grid[x][j] + grid[x][j + 1] + grid[x][j + 2];
                    if (rowSum != sum) {
                        valid = false;
                        break;
                    }
                }

                // Check columns
                for (int y = j; y < j + 3; y++) {
                    int colSum = grid[i][y] + grid[i + 1][y] + grid[i + 2][y];
                    if (colSum != sum) {
                        valid = false;
                        break;
                    }
                }

                // Check diagonals
                int diag1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                int diag2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

                if (diag1 != sum || diag2 != sum)
                    valid = false;

                if (valid)
                    count++;
            }
        }
        return count;
    }
};

int main() {
    // Example input
    vector<vector<int>> grid = {
        {4, 3, 8, 4},
        {9, 5, 1, 9},
        {2, 7, 6, 2}
    };

    Solution obj;
    int result = obj.numMagicSquaresInside(grid);

    cout << "Number of magic squares: " << result << endl;

    return 0;
}