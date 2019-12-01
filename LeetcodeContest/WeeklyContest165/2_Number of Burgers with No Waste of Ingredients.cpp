class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x=tomatoSlices-2*cheeseSlices;
        
        if (x%2)
            return vector<int>();
        
        x=x/2;
        int y=cheeseSlices-x;
        
        if (x>=0 && y>=0)
            return vector<int>{x,y};
        else 
            return vector<int>();
    }
};