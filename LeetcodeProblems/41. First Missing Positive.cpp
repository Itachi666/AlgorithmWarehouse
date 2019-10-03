// Runtime: 4 ms
// Memory Usage: 8.6 MB

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while (i<nums.size())
            if (nums[i]>0 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i])
            {
                if (nums[i]-1<=i)
                {
                    swap(nums[i], nums[nums[i]-1]);
                    i++;
                }
                else
                    while (nums[i]-1>i && nums[nums[i]-1]!=nums[i])
                        swap(nums[i], nums[nums[i]-1]);
            }
            else
                i++;
        
        for (int i=0;i<nums.size();i++)
            if (nums[i]!=i+1)
                return i+1;
        return nums.size()+1;
    }
};