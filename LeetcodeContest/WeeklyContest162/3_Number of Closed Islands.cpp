class Solution {
public:
    bool f[102][102]={false};
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int ans=0, n=0, m=0;
    
    void bfs(int a, int b, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push(make_pair(a,b));
        
        while (!q.empty()) {
            auto now=q.front();
            q.pop();
            f[now.first][now.second]=true;
            
            for (int i=0;i<4;i++) {
                int x=now.first+dir[i][0];
                int y=now.second+dir[i][1];
                
                if (x>=0 && y>=0 && x<n && y<m && !grid[x][y] && !f[x][y])
                    q.push(make_pair(x,y));
            }
            
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        if (n==0)
            return ans;
        m=grid[0].size();
        if (m==0)
            return ans;
        
        for (int i=0;i<n;i++) {
            if (grid[i][0]==0 && !f[i][0]) {
                bfs(i,0,grid);
            }
            if (grid[i][m-1]==0 && !f[i][m-1]) {
                bfs(i,m-1,grid);
            }
        }
        
        for (int j=0;j<m;j++) {
            if (grid[0][j]==0 && !f[0][j]) {
                bfs(0,j,grid);
            }
            
            if (grid[n-1][j]==0 && !f[n-1][j]) {
                bfs(n-1,j,grid);
            }
        }
        
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (grid[i][j]==0 && !f[i][j]) {
                    bfs(i,j,grid);
                    ans++;
                }
        
        return ans;
    }
};