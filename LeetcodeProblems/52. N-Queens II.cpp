// Runtime: 0 ms
// Memory Usage: 880.6 KB

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
    
    void findall(int now,int n,vector<queen>& map,int* answer)
    {
        if (now==n)
        {
            *answer=*answer+1;
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
    
    int totalNQueens(int n) {
        vector<queen> map;
        int answer=0;
        for (int i=0;i<n;i++)
        {
            queen t={0,i};
            map.push_back(t);
            findall(1,n,map,&answer);
            map.pop_back();
        }
        
        
        return answer;
        
    }
};