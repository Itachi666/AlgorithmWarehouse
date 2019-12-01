class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        
        vector<vector<int>> dp = matrix;
        
        for (int l=2;l<=min(n,m);l++) {
            for (int i=l-1;i<n;i++) 
                for (int j=l-1;j<m;j++)
                    if (matrix[i][j]==1 && dp[i-1][j]>=l-1 && dp[i][j-1]>=l-1 && matrix[i-l+1][j-l+1]==1)
                        dp[i][j]=l;
        }
        
//         for (int i=0;i<n;i++) {
//             for (int j=0;j<m;j++)
//                 cout<<dp[i][j]<<' ';
//             cout<<endl;
//         }
        int ans=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++)
                ans+=dp[i][j];
        }
            
        return ans;
    }
};