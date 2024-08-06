/*
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
 
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    // Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxArea = 0;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    // BFS Initialization
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;
                    int area = 0;
                    
                    while (!q.empty()) {
                        //auto [x, y] = q.front();
                        auto cur = q.front();
                        int x = cur.first;
                        int y = cur.second;
                        q.pop();
                        area++;
                        
                        for (auto dir : directions) {
                            int newX = x + dir[0];
                            int newY = y + dir[1];
                            
                            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1 && !visited[newX][newY]) {
                                visited[newX][newY] = 1;
                                q.push({newX, newY});
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends