//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis){
       vis[i] = 1;
       for(int j=0;j<adj.size();j++){
           if(!vis[j] && adj[i][j]==1) dfs(j, adj ,vis);
       }
    }

    int numProvinces(vector<vector<int>> adj, int V) {
        int n = adj.size();
        int m = adj[0].size();
        int c = 0;
        vector<bool> vis(n, false);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                dfs(i,adj,vis);
            }
        }
        return c;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends