class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int answer=0;
        vector<int> even;
        even.push_back(-1);
        
        for (int i=0;i<nums.size();i++)
            if (nums[i]%2)
                even.push_back(i);
        
        even.push_back(nums.size());
        if (even.size()-2<k)
            return answer;
        
        for (int i=1;i<even.size()-k;i++) {
            answer+=(even[i]-even[i-1]) * (even[i+k]-even[i+k-1]);
        }
            
        
        
        return answer;
    }
};