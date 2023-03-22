//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int mod = 1e9+7;
class Solution {
  public:
  
    int f(int ind, vector<int> &arr, vector<vector<int>> &dp, int sum){
        if(ind == 0)
        {
            if(sum==0 && arr[0]==0)  return 2;
            if(sum==0 || arr[0]==sum) return 1;
            return 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        int nottake = f(ind-1, arr, dp, sum)%mod;
        int take = false;
        if(arr[ind] <= sum) take = f(ind-1,arr,dp,sum-arr[ind])%mod;
        return dp[ind][sum] = (take%mod + nottake%mod)%mod;
	}
	
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        int target = (sum-d)/2;
        if(sum-d<0) return 0;
        if((sum-d)&1) return 0;
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return f(n-1,arr,dp,target);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends