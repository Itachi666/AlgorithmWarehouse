class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for (auto it:nums) {
            int count=0;
            while (it!=0) {
                count++;
                it=it/10;
            }
            if (count%2==0)
                ans++;
        }
        return ans;
    }
};