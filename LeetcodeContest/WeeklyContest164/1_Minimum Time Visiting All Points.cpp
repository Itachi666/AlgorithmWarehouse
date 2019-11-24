class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        
        for (int i=1;i<points.size();i++) {
            vector<int>& x=points[i-1];
            vector<int>& y=points[i];
            
            int dx=abs(x[0]-y[0]);
            int dy=abs(x[1]-y[1]);
            
            ans+=min(dx, dy) + abs(dx-dy);
        }
        
        return ans;
    }
};