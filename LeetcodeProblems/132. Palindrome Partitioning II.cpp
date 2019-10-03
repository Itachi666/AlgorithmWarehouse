// Runtime: 1264 ms
// Memory Usage: 557.2 MB

class Solution {
public:
    bool check(string s,int l,int r)
    {
        if (l==r)
            return true;
    
        while (l<r)
        {
            if (s[l]==s[r])
            {
                l++;
                r--;
            }
            else
                return false;
        }   
        return true;
    }
   
    int minCut(string s) {
        vector<int> f;
        bool a[2002][2002];
        int n=s.length();
        
        for (int i=0;i<n;i++)
            for (int j=i;j<n;j++)
                a[i+1][j+1]=check(s,i,j);
        
    
        f.push_back(-1);
        f.push_back(0);
        
        for (int i=2;i<=n;i++)
            for (int j=i;j>0;j--)
                if (a[j][i])
                {
                    if (f.size()==i)
                        f.push_back(f[j-1]+1);
                    else
                        f[i]=min(f[i],f[j-1]+1);
                }
                    
        return f[n];
    }
};