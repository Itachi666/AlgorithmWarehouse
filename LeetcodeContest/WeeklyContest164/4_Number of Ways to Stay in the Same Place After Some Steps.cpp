class Solution {
public:
    const int T = 1e9+7;
    
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1, vector<int>(steps+1, 0));
        dp[0][0]=1;
        for (int i=1;i<=steps;i++) {
            for (int j=0;j<=i && j<arrLen;j++) {
                if (j==0) {
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j+1]) % T;
                    continue;
                }
                if (j==i || j==arrLen) {
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]) % T;
                    continue;
                }
                
                dp[i][j]=((dp[i-1][j-1]+dp[i-1][j]) % T + dp[i-1][j+1]) % T;
            }
        }
        
        return dp[steps][0];
    }
};