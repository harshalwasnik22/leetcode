//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int lcs(string s, string r){
        vector<vector<int>> dp(s.size()+1, vector<int> (r.size()+1, 0));
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=r.size();j++){
                if(s[i-1] == r[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[s.size()][r.size()];
    }
    int longestPalinSubseq(string A) {
        string B = A;
        reverse(A.begin(), A.end());
        
        return lcs(A,B);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends