class Solution {
public:
    set<string> word;
    unordered_map<string, string> father;

    vector<string> ans;
    
    string find(string x) {
        return father[x]==x ? x : find(father[x]);
    }
    
    void dfs(int l, string s, vector<vector<string>>& syn) {
        if (l>=s.length()) {
            ans.push_back(s);
            return;
        }
        
        int r=0;
        
        while (l+r<s.length() && s[l+r]!=' ')
            r++;
        string w=s.substr(l,r);
        // cout<<l<<' '<<l+r<<' '<<w<<' '<<s<<endl;
        
        if (word.find(w)!=word.end()) {
            for (auto& k:word)
                if (find(k)==find(w)) {
                    int tr=0;
                    string tmp=s.substr(0,l)+k+s.substr(l+r);
                    while (l+tr<tmp.length() && tmp[l+tr]!=' ')
                        tr++;
                    dfs(l+tr+1, tmp, syn);
                }
        } else 
            dfs(l+r+1, s, syn);
    }
    
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        if (synonyms.empty())
            return vector<string>(1,text);
    
    
        for (int i=0;i<synonyms.size(); i++) {
            word.insert(synonyms[i][0]);
            word.insert(synonyms[i][1]);
            
            if (father.find(synonyms[i][0])==father.end())
                father[synonyms[i][0]]=synonyms[i][0];
            
            if (father.find(synonyms[i][1])==father.end())
                father[synonyms[i][1]]=synonyms[i][1];
            
            father[find(synonyms[i][1])]=find(synonyms[i][0]);
        }
        
        dfs(0, text, synonyms);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};