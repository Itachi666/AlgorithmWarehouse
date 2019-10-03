class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> cost;
        cost.push_back(0);
        for (int i=1;i<=s.length();i++) 
            cost.push_back(cost[i-1]+abs(s[i-1]-t[i-1]));
        
        int answer=0;
        int j=1;
        for (int i=1;i<=s.length();i++)
        {
            while (j<=s.length() && cost[j]-cost[i-1]<=maxCost)
                j++;
            answer=max(j-i, answer);
        }
        return answer;
    }
};