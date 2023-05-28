//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int M = 1e9+7;
    int f(int ind, int sum, vector<int>& arr, vector<vector<int>> &dp){
        if(ind<0) return sum==0;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int ans = f(ind-1, sum, arr, dp)%M;
        if(arr[ind]<=sum) ans += f(ind-1, sum-arr[ind], arr, dp)%M;
        return dp[ind][sum] = ans%M;
    }
    int findTargetSumWays(vector<int>&arr ,int d) {
        int n = arr.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        int target = (sum-d)/2;
        if(sum-d <0 || (sum-d)&1 ) return 0;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, target, arr, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends