class Solution {
public:
    vector<bool> came;
    
    bool dfs(int x, vector<int>& arr) {
        if (x<0 || x>arr.size() || came[x])
            return false;
        
        came[x]=true;
        
        int t=arr[x];
        
        if (t==0)
            return true;
        
        return dfs(x-t, arr) || dfs(x+t, arr);
    }
    
    bool canReach(vector<int>& arr, int start) {
        came.clear();
        came.resize(arr.size(), false);
        
        return dfs(start, arr);
    }
};