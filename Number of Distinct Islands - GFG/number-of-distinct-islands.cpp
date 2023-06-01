//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private: 
        void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, 
        vector<pair<int,int>> &vec, int r0, int c0){
            int n = grid.size();
            int m = grid[0].size();
            
            vis[r][c]=1;
            vec.push_back({r-r0, c-c0});
            
            int d[] = {0, -1, 0, 1, 0};
            
            for(int i=0;i<4;i++){
                int nr = r + d[i];
                int nc = c + d[i+1];
            
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                    dfs(nr, nc, vis, grid, vec, r0, c0);
                }
            }
        }
        
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,vis,grid,vec,i,j);
                    s.insert(vec);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends