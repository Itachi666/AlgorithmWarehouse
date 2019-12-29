class Solution {
public:
    int n, m;
    long long ans=0, count=0;
    int T=1e9+7;
    vector<vector<int>> dp;
    vector<vector<int>> f;
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        m=board[0].size();
        
        dp.clear();
        dp.resize(n+1, vector<int>(m+1,0));
        f.clear();
        f.resize(n+1, vector<int>(m+1,0));
        
        board[0][0]='0';
        
        for (int i=n-1;i>=0;i--)
            for (int j=n-1;j>=0;j--) 
                if (board[i][j]!='X' && board[i][j]!='S') {
                    dp[i][j]=max(max(dp[i+1][j], dp[i][j+1]), dp[i+1][j+1])+board[i][j]-'0';
                }
        
        ans=dp[0][0];
        
        board[n-1][m-1]='0';
        
        f[0][0]=1;
        
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (board[i][j]!='X') {
                    
                    int t=dp[i][j]-(board[i][j]-'0');
                    
                    if (t==dp[i+1][j])
                        f[i+1][j]=(f[i+1][j]+f[i][j]) % T;
                    if (t==dp[i][j+1])
                        f[i][j+1]=(f[i][j+1]+f[i][j]) % T;
                    if (t==dp[i+1][j+1])
                        f[i+1][j+1]=(f[i+1][j+1]+f[i][j]) % T;
                    
                }
        
        count=f[n-1][m-1];
        
        if (count==0)
            ans=0;
        
        return vector<int>{ans % T, count % T};
    }
};