class Solution {
public:
    unordered_map<string, int> f, leef;
    
    bool search(int x, string& s, vector<vector<string>>& regions) {
        vector<string>& t=regions[x];
        
        if (t[0]==s)
            return true;
        
        for (int i=1;i<t.size();i++) {
            if (t[i]==s)
                return true;
            if (leef.find(t[i])!=leef.end() && search(leef[t[i]], s, regions))
                return true;
                
        }
        return false;
    }
    
    string get(int x, string& s, vector<vector<string>>& regions) {
        if (search(x, s, regions))
            return regions[x][0];
        else
            return get(f[regions[x][0]], s, regions);
    }
    
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        for (int j=0;j<regions.size();j++) {
            vector<string>& r=regions[j];
            leef[r[0]]=j;
            for (int i=1;i<r.size();i++)
                f[r[i]]=j;
        }
        string ans;
        if (leef.find(region1)!=leef.end())
            ans=get(leef[region1], region2, regions);
        else
            ans=get(f[region1], region2, regions);
        
        return ans;
    }
};