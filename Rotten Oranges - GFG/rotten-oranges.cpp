//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m] = {0};
        int fresh=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else vis[i][j]=0;
                if(grid[i][j] == 1) fresh++;
            }
        }
        
        int d[] = {0, 1, 0, -1, 0};
        int cnt=0, mx=0;
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            mx = max(time, mx);
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr = row + d[i];
                int nc = col + d[i+1];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1 && !vis[nr][nc]){
                    q.push({{nr, nc}, time+1});
                    vis[nr][nc] = 2;
                    cnt++;
                }
            }
        }
        if(cnt != fresh) return -1;
        return mx;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends