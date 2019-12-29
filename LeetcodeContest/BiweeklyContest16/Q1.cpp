class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int right=-1;
        for (int i=arr.size()-1;i>=0;i--) {
            int t=arr[i];
            arr[i]=right;
            right=max(right, t);
        }
        return arr;
    }
};