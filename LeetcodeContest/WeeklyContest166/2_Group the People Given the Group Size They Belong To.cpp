class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>> group(n+1, vector<int>()), ans;
        
        for (int i=0;i<n;i++)
            group[groupSizes[i]].push_back(i);
        
        for (int i=1;i<=n;i++) {
            vector<int> t;
            
            if (!group[i].empty()) {
                for (int j=0;j<group[i].size();j++) {
                    t.emplace_back(group[i][j]);
                    if ((j+1)%i==0) {
                        ans.emplace_back(t);
                        t.clear();
                    }
                }
            }
        }
        return ans;
    }
};