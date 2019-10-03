// Runtime: 8 ms
// Memory Usage: 8.8 MB

class Solution {
public:
    int left=0;
    int get_the_right(vector<int>& nums, int l, int r)
    {
        if (l>=r)
            return l;
    
        int m=(l+r)/2;
        
        if (nums[m]>nums[m+1])
            return m;
        
        if (nums[m]>=nums[left])
            return get_the_right(nums, m+1, r);
        else
            return get_the_right(nums, l, m);
    }
    
    int findMin(vector<int>& nums) {
        while (left<nums.size() && nums[left]==nums[nums.size()-1])
            left++;
        if (left==nums.size())
            return nums[0];
        int k=get_the_right(nums, left, nums.size()-1);
        //cout<<left<<endl;
        if (k<nums.size()-1)
            left=0;
        return nums[(k+1+left)%nums.size()];
    }
};