// Runtime: 8 ms
// Memory Usage: 9.1 MB

class Solution {
public:
    int trap(vector<int>& height) {
        int h=0;
        for (int i=0;i<height.size();i++)
            h=max(h,height[i]);
        
        int lefth=0,righth=0,ans=h*height.size();
        for (int i=0;i<height.size();i++)
        {
            lefth=max(lefth, height[i]);
            ans-=h-lefth;
        }
        
        for (int i=height.size()-1;i>=0;i--)
        {
            righth=max(righth, height[i]);
            ans-=h-righth;
            ans-=height[i];
        }
        return ans;
    }
};