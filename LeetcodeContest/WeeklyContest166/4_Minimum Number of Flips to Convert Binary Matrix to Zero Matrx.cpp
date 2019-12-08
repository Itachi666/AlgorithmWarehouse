class Solution {
public:
    int n, m;
    
    bool checkzero(vector<vector<bool>>& mat) {
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (mat[i][j])
                    return false;
        
        return true;
    }
    
    vector<vector<bool>> trans(vector<vector<bool>> mat, int x, int y) {
        mat[x][y]=!mat[x][y];
        if (x-1>=0)
            mat[x-1][y]=!mat[x-1][y];
        if (x+1<n)
            mat[x+1][y]=!mat[x+1][y];
        
        if (y+1<m)
            mat[x][y+1]=!mat[x][y+1];
        if (y-1>=0)
            mat[x][y-1]=!mat[x][y-1];
        
        return mat;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        vector<vector<bool>> M(n, vector<bool>(m, false));
        
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (mat[i][j])
                    M[i][j]=true;
        
        if (checkzero(M))
            return 0;
        set<vector<vector<bool>>> used;
        queue<vector<vector<bool>>> q;
        queue<int> count;
        
        used.insert(M);
        q.push(M);
        
        count.push(0);
        
        
        
        while (!q.empty()) {
            int c=count.front();
            vector<vector<bool>> t=q.front();
            count.pop();
            q.pop();
            
            // for (int i=0;i<n;i++) {
            //     for (int j=0;j<m;j++)
            //         cout<<t[i][j]<<' ';
            //     cout<<endl;
            // }
            
            // if (checkzero(t))
            //     return count;
            
            for (int i=0;i<n;i++)
                for (int j=0;j<m;j++) 
                {
                        vector<vector<bool>> a=trans(t, i, j);
                        if (checkzero(a))
                            return c+1;
                    
                        if (used.find(a)!=used.end())
                            continue;
                        else 
                            used.insert(a);
                    
                        q.push(a);
                        count.push(c+1);
                    }
            
        }
        
        return -1;
    }
};