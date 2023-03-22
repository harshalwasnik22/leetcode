//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    // bool f(int ind, int sum, vector<int> &a, vector<vector<int>> &dp){
    //     if(sum == 0) return 1;
    //     if(ind == 0) return (a[0]==sum);
    //     if(dp[ind][sum] != -1) return dp[ind][sum];
    //     bool nottake = f(ind-1, sum,a,dp);
    //     bool take = false;
    //     if(sum >= a[ind]) take = f(ind-1, sum-a[ind],a,dp);
    //     return dp[ind][sum] = take | nottake;
    // }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        
        for(int i=0;i<n;i++) dp[i][0] = true;
        
        if(arr[0]<=sum) dp[0][arr[0]] = true;
        
        for(int i=1;i<n;i++){
            for(int k=1;k<=sum;k++){
                bool nottake = dp[i-1][k];
                bool take = false;
                if(k >= arr[i]) take = dp[i-1][k-arr[i]];
                dp[i][k] = take | nottake;
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends