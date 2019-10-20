class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //sort(coordinates.begin(), coordinates.end());
        
        int lx=coordinates[1][0]-coordinates[0][0];
        int ly=coordinates[1][1]-coordinates[0][1];
        for (int i=1;i<coordinates.size();i++) {
            int x=coordinates[i][0]-coordinates[0][0];
            int y=coordinates[i][1]-coordinates[0][1];
            
            if (y*lx!=x*ly)
                return false;
        }
        
        return true;
    }
};