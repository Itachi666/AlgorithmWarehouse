class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans(searchWord.size(), vector<string>());
        sort(products.begin(), products.end());
        
        for (auto& p:products) 
            if (p.length()>=1 && p[0]==searchWord[0]) 
                ans[0].push_back(p);

        for (int i=1;i<searchWord.size();i++) {  
            for (auto& p:ans[i-1])
                if (p.length()>i && p[i]==searchWord[i])
                    ans[i].push_back(p);
        }
        
        for (int i=0;i<searchWord.size();i++)
            if (ans[i].size()>3) 
                ans[i]=vector<string>{ans[i][0], ans[i][1], ans[i][2]};
        
        return ans;
    }
};