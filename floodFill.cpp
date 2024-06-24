#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // Depth-First Search (DFS) helper function to fill the connected region
    void dfs(int row, int col, vector<vector<int>>& images, vector<vector<int>>& ans, int initColor, int finalColor) {
        // Change the color of the current cell
        ans[row][col] = finalColor;

        // Get the dimensions of the image
        int m = ans.size();
        int n = ans[0].size();

        // Arrays to explore 4-directionally (right, up, left, down)
        int delX[] = {0, -1, 0, 1};
        int delY[] = {1, 0, -1, 0};

        // Explore all four directions
        for (int i = 0; i < 4; i++) {
            int x = row + delX[i];
            int y = col + delY[i];

            // Check if the new position is within bounds and has the initial color and not already colored
            if (x >= 0 && x < m && y >= 0 && y < n && images[x][y] == initColor && ans[x][y] != finalColor) {
                // Recursively call dfs on the next cell
                dfs(x, y, images, ans, initColor, finalColor);
            }
        }
    }

public:
    // Main function to perform flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Create a copy of the original image to store the result
        vector<vector<int>> ans = image;

        // Get the initial color of the starting cell
        int initColor = image[sr][sc];

        // Start the DFS from the initial cell
        dfs(sr, sc, image, ans, initColor, color);

        // Return the modified image
        return ans;
    }
};


int main(){
		
	vector<vector<int>>image{
	    {0,0,0},
	    {1,1,0},
	    {1,1,1}
	};
	

	Solution obj;
	vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}