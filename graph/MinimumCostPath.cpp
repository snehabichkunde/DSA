/*
Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 

Note: It is assumed that negative cost cycles do not exist in the input matrix.


 */





//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        vector<vector<int>>v(n, vector<int>(n, INT_MAX));
        vector<vector<int>>visited(n, vector<int>(n, 0));
        v[0][0] = grid[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({grid[0][0],{0, 0}});
        int arr[4][2] = {{0,1}, {1,0}, {-1,0}, {0, -1}};
        while(!q.empty()){
            auto cur = q.top();
            q.pop();
            int x = cur.second.first;
            int y = cur.second.second;
            if(visited[x][y]) continue;
            visited[x][y] =1;
            for(auto dir : arr){
                int newX = x+ dir[0];
                int newY = y+dir[1];
                if(newX<n&&newX>=0&&newY<n&&newY>=0&&!visited[newX][newY]){
                    int newcost = v[x][y]+grid[newX][newY];
                    if(v[newX][newY]> newcost){
                        v[newX][newY] = newcost;
                        q.push({newcost, {newX, newY}});
                    }
                }
            }
        }
        return v[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends