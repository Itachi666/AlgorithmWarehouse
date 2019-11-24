class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> x(m, 0),y(n,0);
        
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                if (grid[i][j]) {
                    x[i]++;
                    y[j]++;
                }
                    
        int ans=0;
        
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                if (grid[i][j] && (x[i]-1>0 || y[j]-1>0)) {
                    ans++;
                }
    
        return ans;
    }
};