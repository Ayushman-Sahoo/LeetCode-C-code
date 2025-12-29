/*You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.

To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.

For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.

Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.
Example 1:


Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
Output: true
Explanation: The allowed triangular patterns are shown on the right.
Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
Example 2:


Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
Output: false
Explanation: The allowed triangular patterns are shown on the right.
Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.
 

Constraints:

2 <= bottom.length <= 6
0 <= allowed.length <= 216
allowed[i].length == 3
The letters in all input strings are from the set {'A', 'B', 'C', 'D', 'E', 'F'}.
All the values of allowed are unique.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<char>> mp;   // stores allowed patterns
    unordered_map<string, bool> memo;         // memoization to avoid TLE

    // DFS function to check if pyramid can be built
    bool dfs(string bottom) {
        // If already computed, return stored result
        if (memo.count(bottom))
            return memo[bottom];

        // If only one block left, pyramid is complete
        if (bottom.size() == 1)
            return memo[bottom] = true;

        vector<string> nextLevels;
        buildNext(bottom, 0, "", nextLevels);

        // Try all possible next levels
        for (string &next : nextLevels) {
            if (dfs(next))
                return memo[bottom] = true;
        }

        return memo[bottom] = false;
    }

    // Builds all possible upper rows
    void buildNext(string &bottom, int index, string current, vector<string> &nextLevels) {
        // Completed one row
        if (index == bottom.size() - 1) {
            nextLevels.push_back(current);
            return;
        }

        // Take two adjacent blocks
        string key = bottom.substr(index, 2);

        // If no allowed rule, stop
        if (!mp.count(key))
            return;

        // Try all possible top blocks
        for (char ch : mp[key]) {
            buildNext(bottom, index + 1, current + ch, nextLevels);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Store allowed patterns
        for (string &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }

        return dfs(bottom);
    }
};

int main() {
    Solution sol;

    // -------- INPUT --------
    string bottom;
    int n;
    cin >> bottom;     // Example: BCD
    cin >> n;          // number of allowed patterns

    vector<string> allowed(n);
    for (int i = 0; i < n; i++) {
        cin >> allowed[i];
    }

    // -------- OUTPUT --------
    if (sol.pyramidTransition(bottom, allowed))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}