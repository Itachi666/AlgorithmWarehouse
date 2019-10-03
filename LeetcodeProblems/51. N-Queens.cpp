// Runtime: 4 ms
// Memory Usage: 1.1 MB

class Solution {
public:
    struct queen{
        int x;
        int y;
    };
    
    bool check(vector<queen>& map,queen t)
    {
        for (int i=0;i<map.size();i++)
            if (t.y==map[i].y || abs(t.y-map[i].y)==abs(t.x-map[i].x))
                return false;
        return true;
    }
    
    void addmap(vector<queen>& map,vector<vector<string>>& answer)
    {
        string basic_s;
        vector<string> t;
        for (int i=0;i<map.size();i++)
            basic_s+=".";
        
        for (int i=0;i<map.size();i++)
        {
            string s=basic_s;
            s[map[i].y]='Q';
            t.push_back(s);
        }
        answer.push_back(t);
    }
    
    void findall(int now,int n,vector<queen>& map,vector<vector<string>>& answer)
    {
        if (now==n)
        {
            addmap(map,answer);
            return;
        }
        
        for (int i=0;i<n;i++)
        {
            queen t={now,i};
            if (check(map,t))
            {
                map.push_back(t);
                findall(now+1,n,map,answer);
                map.pop_back();
            }
        }   
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<queen> map;
        vector<vector<string>> answer;
        for (int i=0;i<n;i++)
        {
            queen t={0,i};
            map.push_back(t);
            findall(1,n,map,answer);
            map.pop_back();
        }

        return answer;
    }
};