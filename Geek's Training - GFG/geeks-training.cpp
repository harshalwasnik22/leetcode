//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int f(int ind, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
        if(dp[ind][last] != -1) return dp[ind][last];
        
        if(ind == 0){
            int mx=0;
            for(int i=0;i<3;i++){
                if(last!=i) mx = max(mx, points[0][i]);
            }
            return dp[ind][last] = mx;
        }
        
        
        int mx=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int point = points[ind][i] + f(ind-1, i, points, dp);
                mx = max(mx, point);
            }
        }
        return dp[ind][last] = mx;
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int> (4, -1));
        return f(n-1 , 3, points, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends