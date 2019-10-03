// Runtime: 128 ms
// Memory Usage: 15 MB

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> f;
        int first=0;
        while (first<p.length()-1 && p[first]=='*')
            first++;
        if (first)
            first--;
        for (int i=first;i<=p.length();i++)
        {
            vector<bool> f_mid(s.length()+1,false);
            if (i==first)
            {
                f_mid[0]=true;
                f.push_back(f_mid);
                continue;
            }
            if (i==first+1 && p[i-1]=='*')
                f_mid[0]=true;
            for (int j=1;j<=s.length();j++)
            {
                if (f[i-first-1][j-1])
                { 
                    if (p[i-1]=='*')
                        f_mid[j]=true;
                    if (p[i-1]=='?')
                        f_mid[j]=true;
                    if (p[i-1]==s[j-1])
                        f_mid[j]=true;
                }
                if (f[i-first-1][j] && p[i-1]=='*')
                    f_mid[j]=true;
                if (f_mid[j-1] && p[i-1]=='*')
                    f_mid[j]=true;
            }
            
            f.push_back(f_mid);
        }
        return f[p.length()-first][s.length()];
    }
};