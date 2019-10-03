// Runtime: 8 ms
// Memory Usage: 10 MB

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<int> mid(m+1,0x7fffffff);
        vector<vector<int>> hdp(n+1,mid);
        
        hdp[n][m-1]=1;
        
        for (int i=n-1;i>=0;i--)
            for (int j=m-1;j>=0;j--)
            {
                hdp[i][j]=min(hdp[i+1][j], hdp[i][j+1]) - dungeon[i][j];
                hdp[i][j]=max(hdp[i][j], 1);
            }
        
        return hdp[0][0];
    }
};