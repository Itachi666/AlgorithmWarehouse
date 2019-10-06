class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> t;
        int ans=1;
        for (int i=0;i<arr.size();i++) {
            if (t.find(arr[i]-difference)==t.end()) 
            {
                t[arr[i]]=1;
                continue;
            } else {
                int& now = t[arr[i]];
                now=max(now, t[arr[i]-difference]+1);
                ans=max(now,ans);
            }
        }
        return ans;
    }
};