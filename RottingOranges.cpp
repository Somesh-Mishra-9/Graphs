#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();    // Number of rows in the grid
        int n = grid[0].size(); // Number of columns in the grid
        int total = 0, count = 0, days = 0;

        queue<pair<int, int>> q; // Queue to store the positions of rotten oranges

        // Loop through the grid to count the total number of non-empty cells
        // and add the initial positions of all rotten oranges to the queue
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                    total++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        // Arrays to represent the four possible directions (right, down, left, up)
        int delX[] = {0, 1, 0, -1};
        int delY[] = {1, 0, -1, 0};

        // Perform BFS to spread the rot to adjacent fresh oranges
        while (!q.empty())
        {
            int k = q.size(); // Number of rotten oranges to process at the current level
            count += k;

            // Process all rotten oranges at the current level
            while (k--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                // Check all four possible directions
                for (int i = 0; i < 4; i++)
                {
                    int a = x + delX[i];
                    int b = y + delY[i];
                    // Skip invalid or non-fresh orange positions
                    if (a < 0 || b < 0 || a >= m || b >= n || grid[a][b] != 1)
                        continue;
                    q.push({a, b}); // Add newly rotten orange to the queue
                    grid[a][b] = 2; // Mark the orange as rotten
                }
            }
            // Increment the number of days if there are more rotten oranges to process
            if (!q.empty())
                days++;
        }

        // If the number of processed cells matches the total, return the number of days
        // Otherwise, return -1 indicating not all fresh oranges could be rotten
        return (count == total) ? days : -1;
    }
};

int main()
{
    return 0;
}