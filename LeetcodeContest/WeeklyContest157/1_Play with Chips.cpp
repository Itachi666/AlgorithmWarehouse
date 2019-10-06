class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int ans=0x7fffffff;
        int l=0,r=0;
        for (int i=0;i<chips.size();i++)
        {
            if (chips[i]%2)
                l++;
            else
                r++;            
        }
        ans=min(l,r);
        return ans;
    }
};