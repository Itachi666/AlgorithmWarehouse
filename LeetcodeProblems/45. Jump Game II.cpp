// Runtime: 12 ms
// Memory Usage: 10.1 MB

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int l=0,r=0,ans=0;
        while (r<nums.size()-1)
        {
            ans++;
            int k=r;
            for (int i=l;i<=k;i++)
            {
                r=max(r,i+nums[i]);
                if (r>=nums.size())
                    break;
            }
            l=l+1;
        }
        return ans;
    }
};