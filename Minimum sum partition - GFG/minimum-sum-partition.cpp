//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
    bool f(int ind, int target, int arr[], vector<vector<int>> &dp){
        if(target == 0) return dp[ind][target] = 1;
        if(ind == 0) return dp[ind][target] = (arr[0] == target);
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool nottake = f(ind-1, target, arr, dp);
        bool take = false;
        if(arr[ind]<=target){
            take = f(ind-1, target-arr[ind], arr, dp);
        }
        
        return dp[ind][target] = take || nottake;
    }
    
	int minDifference(int arr[], int n)  
	{ 
	    int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        for(int i=0;i<=sum;i++){
            bool d = f(n-1,i,arr,dp);
        }
        
        int mii = 1e8;
        for(int i=0;i<=sum;i++){
            if(dp[n-1][i] == true){
                mii = min(mii, abs(i-(sum-i)));
            }
        }
        return mii;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends