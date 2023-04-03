class Solution {
public:
    int f(int ind, int T, vector<vector<int>> &dp, vector<int> &nums){
        
        if(ind == 0){
        if(T==0 && nums[0]==0)
            return 2;
        if(T==0 || T == nums[0])
            return 1;
        return 0;
        }

        if(dp[ind][T]!=-1) return dp[ind][T];
        int nottake = f(ind-1,T,dp,nums);
        int take = 0;
        if(nums[ind]<=T) take = f(ind-1, T-nums[ind], dp, nums);
        return dp[ind][T] = (take + nottake);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0, n = nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        
        if((sum-target)<0) return 0;
        if((sum-target)&1) return 0;
        int s2 = (sum - target)/2;
        vector<vector<int>> dp(n,vector<int> (s2+1, -1));
        return f(n-1,s2,dp,nums);
    }
};