// Runtime: 12 ms
// Memory Usage: 8.6 MB

class Solution {
public:
    bool raw[10][10]={false};
    bool col[10][10]={false};
    bool square[3][3][10]={false};
    bool find=false;
    
    bool table_raw[10][10]={false};
    bool table_col[10][10]={false};
    bool table_square[3][3][10]={false};
    
    
    bool check(int x,int y, int num)
    {
        if (raw[x][num] || col[y][num] || square[x/3][y/3][num])
            return false;
        else
            return true;
    }
    
    void add_num(int x, int y, char n) 
    {
        int num=n-'0';
        raw[x][num]=true;
        col[y][num]=true;
        square[x/3][y/3][num]=true;
    }
    
    void remove_num(int x, int y, int num) 
    {
        if (!table_raw[x][num]) raw[x][num]=false;
        if (!table_col[y][num]) col[y][num]=false;
        if (!table_square[x/3][y/3][num]) square[x/3][y/3][num]=false;
    }
    
    void put_in_num(int x,int y,vector<vector<char>>& board)
    {
        x+=y/9;
        y=y%9;
        while (x<9 && board[x][y]!='.')
        {
            y++;
            x+=y/9;
            y=y%9;
        }
        if (x==9)
        {
            find=true;
            return;
        }
            
        
        for (int i=1;i<=9;i++)
            if (check(x,y,i))
            {
                board[x][y]='0'+i;
                add_num(x,y,board[x][y]);
                put_in_num(x,y+1,board);
                if (find)
                    return;
                board[x][y]='.';
                remove_num(x,y,i);
            }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                if (board[i][j]!='.')
                {
                    add_num(i,j,board[i][j]);
                    int num=board[i][j]-'0';
                    table_raw[i][num]=true;
                    table_col[j][num]=true;
                    table_square[i/3][j/3][num]=true;
                }
        put_in_num(0,0,board);
    }
};