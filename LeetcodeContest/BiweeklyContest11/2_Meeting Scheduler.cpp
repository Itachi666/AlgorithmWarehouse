class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int x=0,y=0;
        vector<int> answer;
        
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        
        while (x<slots1.size() && y<slots2.size()) {
            while (x<slots1.size() && slots1[x][1]<=slots2[y][0])
                x++;
            
            if (x==slots1.size())
                break;
            
            //cout<<x<<' '<<y<<endl;
            
            if (slots2[y][1]>slots1[x][0]) {
                int l=max(slots1[x][0], slots2[y][0]);
                int r=min(slots1[x][1], slots2[y][1]);
                //printf("%d %d %d %d\n", x,y,l,r);
                if (r-l>=duration)
                {
                    answer.push_back(l);
                    answer.push_back(l+duration);
                    return answer;
                }
                y++;
            }
        
            while (y<slots2.size() && slots2[y][1]<=slots1[x][0])
                y++;
            //cout<<x<<' '<<y<<endl;
            
            if (y==slots2.size())
                break;
            
            if (slots1[x][1]>slots2[y][0]) {
                int l=max(slots1[x][0], slots2[y][0]);
                int r=min(slots1[x][1], slots2[y][1]);
                //printf("%d %d %d %d\n", x,y,l,r);
                if (r-l>=duration)
                {
                    answer.push_back(l);
                    answer.push_back(l+duration);
                    return answer;
                }
                x++;
            }
        }
        
        return answer;
    }
};