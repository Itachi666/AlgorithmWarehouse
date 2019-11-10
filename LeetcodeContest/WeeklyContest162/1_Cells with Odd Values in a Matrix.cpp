class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int ans=0;
        int dp[51][51]={0};
        
        for (auto indic:indices) {
            for (int i=0;i<m;i++) 
                dp[indic[0]][i]++;
            for (int i=0;i<n;i++)
                dp[i][indic[1]]++;
        }
        
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (dp[i][j]%2)
                    ans++;
        
        return ans;
    }
};