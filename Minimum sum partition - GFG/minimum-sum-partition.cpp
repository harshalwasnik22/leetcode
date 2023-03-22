//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	   // int n = nums.size();
        int target = 0;
        for(int i=0;i<n;i++) target += nums[i];

        vector<vector<bool>> dp(n, vector<bool> (target+1, false));
        for(int i=0; i<n;i++) dp[i][0] = true;
        if(nums[0]<=target) dp[0][nums[0]] =true;

        for(int i=1;i<n;i++){
            for(int k=1;k<=target;k++){
                bool nottake = dp[i-1][k];

                bool take = false;
                if(nums[i] <= k) take = dp[i-1][k-nums[i]];

                dp[i][k] = take || nottake;
            }
        }
        
        int mini = 1e9;
        for (int i = 0; i <= target; i++) {
            if (dp[n - 1][i] == true) {
                int diff = abs(i - (target - i));
                mini = min(mini, diff);
            }
        }
        return mini;
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