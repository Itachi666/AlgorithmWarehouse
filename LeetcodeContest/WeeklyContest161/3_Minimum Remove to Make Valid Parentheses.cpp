class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> sta;
        vector<int> place;
        
        
        
        string answer;
        
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(') {
                sta.push(i);
            } 
            if (s[i]==')') {
                if (sta.empty()) {
                    place.push_back(i);
                } else {
                    sta.pop();
                }
            } 
        }
        
        while (!sta.empty()) {
            place.push_back(sta.top());
            sta.pop();
        }
        if (!place.empty())
            sort(place.begin(), place.end());
        int j=0;
        
        for (int i=0;i<s.size();i++) {
            if (j<place.size() && place[j]==i) {
                j++; 
            }
            else 
                answer+=s[i];
        }
        
        return answer;
    }
};