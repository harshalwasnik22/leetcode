//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        // int n = price.size();
       vector<vector<int>> dp(n, vector<int> (n+1, -1));
       
      for(int i=0;i<=n;i++) dp[0][i]= i*price[0];

        for(int ind=1;ind<n;ind++){
          for(int w=0;w<=n;w++){
                
                int nottake = dp[ind-1][w];
                    
                int take = INT_MIN;
                if((ind+1)<=w){
                    take = price[ind] + dp[ind][w-(ind+1)];
                }
                
                dp[ind][w] =  max(nottake, take);
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends