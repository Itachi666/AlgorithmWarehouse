// Runtime: 28 ms
// Memory Usage: 10.5 MB

class Solution {
public:
    int candy(vector<int>& ratings) {
        int answer=0;
       
        vector<int> candy(ratings.size(), 1);
        
        for (int i=1;i<ratings.size();i++)
            if (ratings[i]>ratings[i-1])
                candy[i]=candy[i-1]+1;
        
        for (int i=ratings.size()-2;i>=0;i--)
            if (ratings[i]>ratings[i+1])
                candy[i]=max(candy[i], candy[i+1]+1);
        
        for (auto i:candy)
            answer+=i;
        
        return answer;
    }
};