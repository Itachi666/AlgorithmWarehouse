class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> m;
        int n=nums.size();
        
        if (n%k!=0)
            return false;
        
        for (auto& it:nums)
            m[it]++;
        
        while (n>0) {
            int f=m.begin()->first;
            for (int i=0;i<k;i++) {
                if (m.find(f)==m.end())
                    return false;
                
                m[f]--;
                if (m[f]==0)
                    m.erase(f);
                f++;
            }
            
            n-=k;
        }
        
        return true;
    }
};