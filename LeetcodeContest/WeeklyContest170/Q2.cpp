class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> sum(arr.size()+1, 0);
        
        for (int i=1;i<=arr.size();i++)
            sum[i]=sum[i-1] ^ arr[i-1];
        
        vector<int> ans;
        
        for (auto& q:queries) {
            int x=q[0]+1;
            int y=q[1]+1;
            ans.push_back(sum[y] ^ sum[x-1]);
        }
        
        return ans;
    }
    
};