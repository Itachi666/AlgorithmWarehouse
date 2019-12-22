class Solution {
public:
    unordered_set<int> key, hasbox, opened;
    int ans=0;
    
    
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> box;
        for (auto it:initialBoxes)
            box.push(it);
        
        while (!box.empty()) {
            int b=box.front();
            box.pop();
            
            if (opened.find(b)!=opened.end())
                continue;
            // cout<<b<<endl;
            
            if (status[b]==0 && key.find(b)==key.end()) {
                hasbox.insert(b);
                continue;
            }
            opened.insert(b);
            hasbox.erase(b);
            ans+=candies[b];
            
            for (auto& k:keys[b]) {
                key.insert(k);
                if (hasbox.find(k)!=hasbox.end())
                    box.push(k);
            }
            
            for (auto& c:containedBoxes[b]) {
                box.push(c);
            }
        }
        return ans;
    }
};