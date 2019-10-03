// Runtime: 4 ms
// Memory Usage: 8.3 MB

class Solution {
public:
    int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    int ans=0;
    
    void get_the_path(int x,int y, int count, vector<vector<int>>& grid)
    {
        if (grid[x][y]==2)
        {
            if (count==0)
                ans++;
            return;
        }else{
            for (int i=0;i<4;i++)
            {
                int tx=x+dir[i][0];
                int ty=y+dir[i][1];
                if (tx>=0 && ty>=0 && tx<grid.size() && ty<grid[0].size() && grid[tx][ty]!=-1)
                {
                    grid[x][y]=-1;
                    get_the_path(tx,ty, count-1,grid);
                    grid[x][y]=0;
                }
            }
            
        }
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count=1;
        for (int i=0;i<grid.size();i++)
            for (int j=0;j<grid[0].size();j++)
                if (grid[i][j]==0)
                    count++;

        for (int i=0;i<grid.size();i++)
            for (int j=0;j<grid[0].size();j++)
                if (grid[i][j]==1)
                {
                    grid[i][j]=-1;
                    get_the_path(i,j, count,grid);
                }
        return ans;
    }
};