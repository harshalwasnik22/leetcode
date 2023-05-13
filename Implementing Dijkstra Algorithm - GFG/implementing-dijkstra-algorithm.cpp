//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> s;
        vector<int> dist(V,1e9);
        
        s.insert({0,S});
        dist[S]=0;
        
        while(!s.empty()){
            auto it = *(s.begin());
            int dis = it.first;
            int node = it.second;
            s.erase(it);
            
            for(auto it: adj[node]){
                
                int adjNode = it[0];
                int v = it[1];
                
                if(dis + v < dist[adjNode] ){
                    
                    if(dist[adjNode] != 1e9) 
                        s.erase({dist[adjNode], adjNode});
                    
                    dist[adjNode] = dis + v;
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends