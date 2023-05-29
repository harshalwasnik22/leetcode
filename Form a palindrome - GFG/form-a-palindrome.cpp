//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

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
    
    int countMin(string A){
        int n = A.size();
        string B = A;
        reverse(A.begin(), A.end());
        
        return n - lcs(A,B);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends