class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n,0);
        int count=0;
        for (int i=1;i<n;i++) {
            count+=i;
            ans[i]=i;
        }
            
        ans[0]=-count;
        return ans;
    }
};