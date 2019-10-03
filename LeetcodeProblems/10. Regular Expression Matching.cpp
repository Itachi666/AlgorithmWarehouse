// Runtime: 40 ms
// Memory Usage: 3.7 MB

class Solution {
public:
    bool match(char x,char y)
    {
        if (y=='.')
            return true;
        return (x==y);
    }
    
    bool isMatch(string s, string p) {
        bool f[1000][1000]={false};
        int g[10000]={0};
        f[0][0]=true;

        int slength=s.length();
        int plength=p.length();
        
        for (int i=1;i<=plength;i++)
            if (p[i-1]=='*' && f[0][i-2])
                f[0][i]=true;
        
        for (int i=1;i<=slength;i++)
            for (int j=1;j<=plength;j++)
            {
                if (p[j-1]!='*' && f[i-1][j-1])
                     f[i][j]=match(s[i-1],p[j-1]);
                if (p[j-1]=='*')
                {
                    if (!f[i][j-1] && f[i][j-2])
                    {
                        f[i][j]=true;
                        continue;
                    }
                    if (f[i-1][j] || f[i-1][j-1])
                        f[i][j]=match(s[i-1],p[j-2]);
                }
                //cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
            }
        return f[slength][plength];
    }
};