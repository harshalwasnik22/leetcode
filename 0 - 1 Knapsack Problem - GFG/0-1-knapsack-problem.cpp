//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // int f(int ind, int W, int wt[], int val[], vector<vector<int>> &dp){
    //     if(ind == 0){
    //         if(wt[0]<=W) return val[0]; 
    //         else return 0;
    //     }
        
    //     if(dp[ind][W] != -1) return dp[ind][W];
        
    //     int nottake = f(ind-1,W,wt,val,dp);
    //     int take = INT_MIN;
    //     if(W>=wt[ind]){
    //         take = val[ind] + f(ind-1,W-wt[ind],wt,val,dp);
    //     }
    //     return dp[ind][W] =  max(nottake, take);
    // }
    int dp[1001][1001];
    // dp[ind][W] = till index ind, if knapsack weight is W, then what is max imum value of subset i can acchieve
    // int helper(int W, int wt[], int val[], int n, int ind)
    // {
    //     if(ind==n || W==0) return 0;
    //     if(dp[ind][W]!=-1) return dp[ind][W];
    //     int nottake = helper(W,wt,val,n,ind+1);
    //     int take = INT_MIN;
    //     if(wt[ind]<=W)
    //     take = val[ind]+helper(W-wt[ind],wt,val,n,ind+1);
    //     dp[ind][W] = max(take,nottake);
    //     return dp[ind][W];
    // }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=W;i++) dp[0][i] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int w=0;w<=W;w++)
            {
                int nottake = dp[i-1][w];
                int take = INT_MIN;
                if(wt[i-1]<=w)
                {
                    take = val[i-1]+dp[i-1][w-wt[i-1]];
                }
                dp[i][w] = max(take,nottake);
            }
        }
        return dp[n][W];
        
    //   vector<vector<int>> dp(n, vector<int> (W+1, 0));
       
    //   for(int i=wt[0];i<=W;i++) dp[0][i]=val[0]; 
       
    //   for(int i=0;i<n;i++){
    //         for(int j=0;j<W+1;j++){
    //             cout << dp[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     for(int ind=1;ind<n;ind++){
    //       for(int w=0;w<=W;w++){
                
    //             int nottake = dp[ind-1][w];
                    
    //             int take = INT_MIN;
    //             if(wt[ind]<=w){
    //                 take = val[ind] + dp[ind-1][w-wt[ind]];
    //             }
                
    //             dp[ind][w] =  max(nottake, take);
    //         }
    //     }
        
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<W+1;j++){
    //             cout << dp[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
        
    //     return dp[n-1][W];
    
    }
};





//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends