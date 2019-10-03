// Runtime: 8 ms
// Memory Usage: 8.9 MB

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
            return 0;
        int k=get_the_right(nums, left, nums.size()-1);
    
        if (k<nums.size()-1)
            left=0;
        return (k+1+left)%nums.size();
    }
    
    bool get(int l, int r, int target, vector<int>& nums)
    {
        if (l>=r)
        {
            if (l==nums.size())
                return false;
            if (nums[l]==target)
                return true;
            else
                return false;
        }
        
        int m=(l+r)/2;
        
        if (nums[m]>=target)
            return get(l,m,target,nums);
        else 
            return get(m+1,r,target,nums);
    }
    
    bool search(vector<int>& nums, int target) {
        if (nums.size()==0)
            return false;
        int k=findMin(nums);
        
        if (nums[nums.size()-1]>=target)
            return get(k,nums.size()-1,target,nums);
        else
            return get(0,k-1,target,nums);
    }
};