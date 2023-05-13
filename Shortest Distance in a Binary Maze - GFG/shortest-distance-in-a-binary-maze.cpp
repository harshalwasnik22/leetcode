//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int> (m,1e9));
        if(source.first==destination.first && source.second==destination.second) 
            return 0; 
        dist[source.first][source.second] = 0;
        q.push({0,{source.first, source.second}});
        
        while(!q.empty()){
            
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
            int d[] = {0, 1, 0, -1, 0};
            
            for(int k=0;k<4;k++){
                int nr = row + d[k];
                int nc = col + d[k+1];
                
                
                if(nr >= 0 && nr < n && nc >=0 && nc < m && grid[nr][nc] == 1 && dis+1 < dist[nr][nc]){
                    dist[nr][nc] = dis+1;
                    if(nr == destination.first && nc == destination.second){
                        return dis+1;
                    }
                    q.push({1+dis, {nr, nc}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends