// Algorithm: DP
// Runtime: 1144 ms
// Memory Usage: 9.9 MB

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int left=0, right=0;
        int n=heights.size();
        int ans=0;
        for (int i=0;i<n;i++) {
            if (i!=0 && heights[i]>heights[i-1])
                left=i;
            right=i;
            
            while (left>=0 && heights[left]>=heights[i])
                left--;
            while (right<n && heights[right]>=heights[i])
                right++;
            
            ans=max(ans, heights[i]*(right-left-1));
        }
        return ans;
    }
};