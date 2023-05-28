//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
 
public:
    long long M = 1e9+7;
    int fn(int ind, int sum, int arr[], vector<vector<int>> &dp){
        if(ind<0) return sum==0;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int ans = fn(ind-1, sum, arr, dp)%M;
        if(arr[ind]<=sum) ans += fn(ind-1, sum-arr[ind], arr, dp)%M;
        return dp[ind][sum] = ans%M;
    }
    int perfectSum(int arr[], int n, int sum){
            // Your code goes here
            vector<vector<int>> dp(n, vector<int>(sum+1, -1));
            return fn(n-1, sum, arr, dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends