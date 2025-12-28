/*
You said:
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();        // number of rows
        int n = grid[0].size();     // number of columns
        
        int row = 0;
        int col = n - 1;            // start from top-right
        int count = 0;
        
        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                count += (m - row);
                col--;              // move left
            } else {
                row++;              // move down
            }
        }
        
        return count;
    }
};

int main() {
    int m, n;
    
    cout << "Enter number of rows: ";
    cin >> m;
    
    cout << "Enter number of columns: ";
    cin >> n;
    
    vector<vector<int>> grid(m, vector<int>(n));
    
    cout << "Enter matrix elements (row-wise):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    Solution obj;
    int result = obj.countNegatives(grid);
    
    cout << "Number of negative numbers: " << result << endl;
    
    return 0;
}