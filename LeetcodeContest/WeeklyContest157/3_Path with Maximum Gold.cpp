class Solution {
public:
    int ans=0;
    int used[16][16]={0};
    int dp[16][16]={0};
    
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    
    bool check(int x, int y,vector<vector<int>>& grid) {
        if (x==-1 || x==grid.size() || y==-1 || y==grid[0].size())
            return false;
        
        if (used[x][y] || grid[x][y]==0)
            return false;
        return true;
    }
    
    int dfs(int x,int y,vector<vector<int>>& grid) {
        used[x][y]=1;
        
        int cost=0;
        
        for (int i=0;i<4;i++) {
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];
            
            if (check(xx,yy,grid)) {
                cost=max(cost, dfs(xx,yy, grid));
            }
        }
        used[x][y]=0;
        return cost+grid[x][y];
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        for (int i=0;i<grid.size();i++)
            for (int j=0;j<grid[0].size();j++)
                if (grid[i][j])
                {
                    memset(used, 0, sizeof(used));
                    //memset(dp, 0, sizeof(dp));
                    ans=max(ans, dfs(i,j,grid));
                }
        
        return ans;
    }
};