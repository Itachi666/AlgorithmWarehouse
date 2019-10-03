// Runtime: 12 ms
// Memory Usage: 9.5 MB

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int dp[n+1][m+1]={0};
        
        for (int i=0;i<=n;i++)
            dp[i][0]=i;
        for (int i=0;i<=m;i++)
            dp[0][i]=i;
        
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                dp[i][j]=0x7fffffff;
                dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
                dp[i][j]=min(dp[i][j], dp[i][j-1]+1);
                
                int k=(word1[i-1]!=word2[j-1]);
                
                dp[i][j]=min(dp[i][j], dp[i-1][j-1]+k);
            }
        
        return dp[n][m];
    }
};
