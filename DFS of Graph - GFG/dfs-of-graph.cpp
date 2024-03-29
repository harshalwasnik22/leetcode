//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans , vis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(0,vis,adj, ans);
        }
        return ans;
    }
    
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &ans){
        vis[node] = 1;
        ans.push_back(node);
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]) dfs(adjNode, vis, adj, ans);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends