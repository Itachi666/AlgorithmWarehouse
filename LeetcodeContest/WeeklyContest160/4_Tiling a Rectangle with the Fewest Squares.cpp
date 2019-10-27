class Solution {
public:
    int f[6]={1,2,3,5,8,13};
    int dp[14][14]={0};
    
    int get(int n, int m) {
        if (n<=0 || m<=0)
            return 0x7fffff;
        
        if (n>m) 
            swap(n,m);
        
        if (dp[n][m]!=0x7fffffff)
            return dp[n][m];
        
        for (int i=m/2;i<m;i++)
            dp[n][m]=min(dp[n][m], get(n,i) + get(n,m-i));
        
        for (int i=n/2;i<n;i++)
            dp[n][m]=min(dp[n][m], get(i,m) + get(n-i,m));
        
        if (m-n==2 && m%2==1) 
        {
            int t=(m+1)/2;
            dp[n][m]=min(dp[n][m], 5+get(t-3,4));
        }
        return dp[n][m];
    }
    
    int tilingRectangle(int n, int m) {
        int answer=1;
        
        if (n>m) 
            swap(n,m);
        
        if (n==m)
            return answer;
        
        for (int i=1;i<=13;i++)
            for (int j=1;j<=13;j++)
                dp[i][j]=0x7fffffff;
        
        for (int i=1;i<=13;i++)
            dp[i][i]=1;
        
        dp[1][2]=2;
        for (int i=1;i<5;i++) {
            dp[f[i]][f[i+1]]=dp[f[i-1]][f[i]]+1;
        }
        
        for (int i=2;i<=13;i++)
            dp[1][i]=dp[1][i-1]+1;
        
        for (int i=1;i<=13;i++)
            for (int j=1;j<=13;j++)
                if (dp[i][j]==0x7fffffff)
                    dp[i][j]=get(i,j);

        return dp[n][m];
    }
};