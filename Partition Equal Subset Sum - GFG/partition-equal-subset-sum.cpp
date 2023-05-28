//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool f(int ind, int target, int arr[], vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(ind == 0) return (arr[0] == target);
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool nottake = f(ind-1, target, arr, dp);
        bool take = false;
        if(arr[ind]<=target){
            take = f(ind-1, target-arr[ind], arr, dp);
        }
        
        return dp[ind][target] = take || nottake;
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        int target = sum/2;
        if(sum&1) return false;
        vector<vector<int>> dp(N, vector<int> (target+1, -1));
        return f(N-1, target, arr, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends