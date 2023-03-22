//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool f(int ind, int sum, vector<int> &a, vector<vector<int>> &dp){
        if(sum == 0) return 1;
        if(ind == 0) return (a[0]==sum);
        if(dp[ind][sum] != -1) return dp[ind][sum];
        bool nottake = f(ind-1, sum,a,dp);
        bool take = false;
        if(sum >= a[ind]) take = f(ind-1, sum-a[ind],a,dp);
        return dp[ind][sum] = take | nottake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
        
        for(int i-)
        return f(arr.size()-1, sum, arr,dp);
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