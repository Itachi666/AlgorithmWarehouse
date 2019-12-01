class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        
        for (auto& it:intervals) {
            if (it[1]<=toBeRemoved[0])
                ans.push_back(it);
            
            if (it[0]>=toBeRemoved[1])
                ans.push_back(it);
            
            if (it[0]<toBeRemoved[0] && toBeRemoved[0]<it[1])
                ans.push_back(vector<int>{it[0], toBeRemoved[0]});
            
            if (it[0]<toBeRemoved[1] && toBeRemoved[1]<it[1])
                ans.push_back(vector<int>{toBeRemoved[1], it[1]});
        }
        
        return ans;
    }
};