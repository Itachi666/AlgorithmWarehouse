/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> top, vector<int> bot) {
        vector<int> m{(top[0]+bot[0])/2, (top[1]+bot[1])/2};
        // cout<<bot[0]<<' '<<bot[1]<<' '<<top[0]<<' '<<top[1]<<endl;
        if (!sea.hasShips(top, bot))
            return 0;

        if (bot[0]==top[0] && bot[1]==top[1])
            return 1;
        
        if (bot[0]==top[0])
            return countShips(sea, m, bot) + countShips(sea, top, vector<int>{m[0], m[1]+1});
        
        if (bot[1]==top[1])
            return countShips(sea, m, bot) + countShips(sea, top, vector<int>{m[0]+1, m[1]});
//         
        return countShips(sea, m, bot) + countShips(sea, top, vector<int>{m[0]+1, m[1]+1}) + countShips(sea, vector<int>{m[0], top[1]}, vector<int>{bot[0], m[1]+1}) + countShips(sea, vector<int>{top[0], m[1]}, vector<int>{m[0]+1, bot[1]});
    }
};