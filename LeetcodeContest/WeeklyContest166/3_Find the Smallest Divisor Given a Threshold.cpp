class Solution {
public:
    long long SUM(vector<int>& nums, int t) {
        long long ans=0;
        for (auto& i:nums) 
            ans+=(i%t!=0)+i/t;
        return ans;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long l=1, r=0x7fffffff;
        
        while (l<r) {
            // cout<<l<<' '<<r<<endl;
            
            long long m=(l+r)/2;
            long long s=SUM(nums, m);
            
            if (s>threshold)
                l=m+1;
            else
                r=m;
        }
        return l;
    }
};