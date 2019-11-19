class Solution {
public:
    
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(3,-1e9));
        dp[0][0]=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<3;j++) 
                dp[i+1][(j + nums[i])%3] = max(dp[i][(j + nums[i])%3], dp[i][j]+nums[i]);
        }
    
        return dp[n][0];
    }
};