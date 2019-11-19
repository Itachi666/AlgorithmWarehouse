class Solution {
public:
    int n,m;
    bool BoxPlaced[20][20][20][20]={false};
    int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    queue<pair<int, int>> box, player;
    queue<int> count;
    
    bool checkPush(int x, int y, int px, int py, vector<vector<char>>& g) {
        if (x>=0 && y>=0 && x<n && y<m && BoxPlaced[x][y][px][py]==false && g[x][y]!='#')
            return true;
        return false;
    }
    
    void PushBox(pair<int, int>& b, pair<int, int>& p, int& c, vector<vector<char>>& g) {
        queue<pair<int, int>> players;
        players.push(p);
        vector<vector<bool>> come(n, vector<bool>(m,false));
        come[p.first][p.second]=true;
        
        while (!players.empty()) {
            auto play=players.front();
            players.pop();
            
            for (int i=0;i<4;i++) {
                int x=play.first+dir[i][0];
                int y=play.second+dir[i][1];
                
                if (x>=0 && y>=0 && x<n && y<m && come[x][y]==false && g[x][y]!='#' && b!=make_pair(x,y)) {
                    players.push(make_pair(x,y));
                    come[x][y]=true;
                }
                
                if (x>=0 && y>=0 && x<n && y<m && b==make_pair(x,y) && checkPush(x+dir[i][0], y+dir[i][1], x, y, g)) {
                    box.push(make_pair(x+dir[i][0],y+dir[i][1]));
                    BoxPlaced[x+dir[i][0]][y+dir[i][1]][x][y]=true;
                    player.push(make_pair(x,y));
                    count.push(c+1);   
                }
            }
        }
        
    }
    
    int minPushBox(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();

        pair<int, int> Target;
        
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) {
                if (grid[i][j]=='T') {
                    grid[i][j]='.';
                    Target=make_pair(i,j);
                }
                if (grid[i][j]=='B') {
                    box.push(make_pair(i,j));
                    grid[i][j]='.';
        
                }
                if (grid[i][j]=='S') {
                    player.push(make_pair(i,j));  
                    grid[i][j]='.';
                }
            }
        count.push(0);
        
        while (!box.empty()) {
            auto b=box.front();
            auto p=player.front();
            int c=count.front();
            
            box.pop();
            player.pop();
            count.pop();
            
            if (b==Target) {
                return c;
            }
            
            PushBox(b, p, c, grid);
        }
        return -1;
    }
};