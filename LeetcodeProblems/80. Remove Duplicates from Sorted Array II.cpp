// Runtime: 8 ms
// Memory Usage: 8.7 MB

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1, length=1;
        if (nums.size()==0)
            return 0;
        
        for (int i=1;i<nums.size();i++)
        {
            if (nums[i]==nums[length-1])
            {
                count++;
                if (count>2)
                    continue;
            }else
                count=1;
            swap(nums[length], nums[i]);
            length++;
        }
        return length;
    }
};