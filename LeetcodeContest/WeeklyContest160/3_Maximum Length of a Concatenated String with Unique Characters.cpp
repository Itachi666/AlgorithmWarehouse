class Solution {
public:
    int answer=0;
    
    bool check(string s, set<char>& now) {
        for (int i=0;i<s.length();i++) 
            if (now.find(s[i])!=now.end())
                return false;
        
        return true;
    }
    
    bool checkself(string s) {
        set<char> now;
        for (int i=0;i<s.length();i++) 
            if (now.find(s[i])!=now.end()) {
                return false;
            } else 
                now.insert(s[i]);
        
        return true;
    }
    
    void dfs(string s, set<char> now, int n, vector<string>& arr) {
        if (n==arr.size()) {
            answer=max(answer, (int)s.length());
            return;
        }
        
        bool cself=checkself(arr[n]);
        
        dfs(s, now, n+1, arr);
        
        if (cself && check(arr[n], now)) {
            for (int i=0;i<arr[n].length();i++)
                now.insert(arr[n][i]);
            dfs(s+arr[n], now, n+1, arr);
        }
        
    }
    
    int maxLength(vector<string>& arr) {
        set<char> now;
        dfs("", now, 0, arr);
        
        return answer;
    }
};