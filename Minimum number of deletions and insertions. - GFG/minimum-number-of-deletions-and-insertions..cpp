//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
    
	int minOperations(string A, string B) 
	{
        int n = A.size();
        int m = B.size();
        int k = lcs(A,B);
	    return (n-k) + (m-k);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends