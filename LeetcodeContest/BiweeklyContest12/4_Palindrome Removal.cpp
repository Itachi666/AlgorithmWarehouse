class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int dp[101][101]={0};
        int n=arr.size();
        
        for (int i=0;i<n;i++)
            dp[i][i]=1;
        
        for (int i=0;i<n-1;i++) {
            dp[i][i+1]=2;
            if (arr[i]==arr[i+1])
                dp[i][i+1]=1;
        }
        
        for (int len=3;len<=n;len++) 
            for (int i=0;i<=n-len;i++) 
            {
                int j=i+len-1;
                dp[i][j]=0x7fffffff;
                
                //cout<<i<<' '<<j<<endl;
                for (int k=i;k<=j;k++)
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
                
                if (arr[i]==arr[j])
                    dp[i][j]=min(dp[i][j], dp[i+1][j-1]);
                
            }
        
        return dp[0][n-1];
    }
};