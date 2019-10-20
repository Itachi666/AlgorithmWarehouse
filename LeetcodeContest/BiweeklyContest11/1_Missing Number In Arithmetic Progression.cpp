class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int len=min(abs(arr[1]-arr[0]), abs(arr[arr.size()-1]-arr[arr.size()-2]));
        for (int i=1;i<arr.size();i++)
            if (abs(arr[i]-arr[i-1])!=len)
                return (arr[i-1]+arr[i])/2;
        return arr.back()-len;
    }
};