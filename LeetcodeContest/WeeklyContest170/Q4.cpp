class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0x7fffffff));
        
        for (int i=0;i<n;i++)
            dp[i][i]=0;
        
        for (int i=0;i<n-1;i++)
            if (s[i]==s[i+1])
                dp[i][i+1]=0;
            else
                dp[i][i+1]=1;
        
        for (int l=3;l<=n;l++)
            for (int i=0;i<n-l+1;i++) {
                int j=i+l-1;
                
                dp[i][j]=min(dp[i+1][j], dp[i][j-1]) + 1;
                
                if (s[i]==s[j])
                    dp[i][j]=min(dp[i][j], dp[i+1][j-1]);
            }
        
        return dp[0][n-1];
    }
};