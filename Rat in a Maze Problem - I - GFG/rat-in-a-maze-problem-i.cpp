//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    vector<string> findPath(vector<vector<int>> &m, int n){
        solve(0,0,m,n,"");
        return ans;
    }
    
    void solve(int row, int col, vector<vector<int>> &m, int n, string path){
        if(row < 0 or row >= n or col < 0 or col >= n or m[row][col] == 0) return;
        if(row == n-1 && col == n-1){
            ans.push_back(path);
            return;
        }    
        m[row][col]=0;
        
        solve(row+1, col, m, n, path+'D');
        solve(row-1, col, m, n, path+'U');
        solve(row, col+1, m, n, path+'R');
        solve(row, col-1, m, n, path+'L');
        
        m[row][col]=1;
        return;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends