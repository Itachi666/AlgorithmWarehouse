class Solution {
public:
    int gcd(int x, int y) {
        return (x%y)? gcd(y, x%y) : y;
    }
    
    bool isGoodArray(vector<int>& nums) {
        int now=nums[0];
        
        for (int i=1;i<nums.size();i++)
            now=gcd(now, nums[i]);
        
        
        return (now==1);
    }
};