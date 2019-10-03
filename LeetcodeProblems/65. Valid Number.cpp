// Runtime: 8 ms
// Memory Usage: 9 MB

class Solution {
public:
    bool checkelement(char t)
    {
        if (t>='0' && t<='9')
            return true;
        if (t=='+' || t=='-' || t=='.')
            return true;
        return false;
    }
    
    bool checkdouble(string s, int l, int r, bool haveE)
    {
        if (l==r)
            return false;
        
        unordered_map<char, bool> map;
        map['-']=false;
        map['+']=false;
        map['.']=false;
        map['n']=false;
        for (int i=l;i<r;i++)
            if (checkelement(s[i]))
            {
                if (s[i]=='-' || s[i]=='+')
                {
                    if (i!=l)
                        return false;
                    if (map[s[i]])
                        return false;
                    map['-']=true;
                    map['+']=true;
                }
                
                if (s[i]=='.')
                {
                    if (haveE)
                    {
                        //if (map[s[i]] || i==r-1 || i==l)
                            return false;
                    }else
                    {
                        if (map[s[i]] || l==r-1)
                            return false;
                    }
                    map['.']=true; 
                }
                if (s[i]>='0' && s[i]<='9')
                    map['n']=true;
            }
            else
                return false;
        return map['n'];
    }
    
    bool isNumber(string s) {
        
        bool answer=true;
        
        int l=0,r=s.length();
        while (s[l]==' ' && l<r)
            l++;
        
        while (s[r-1]==' ' && r>l)
            r--;
        
        for (int i=l;i<r;i++)
            if (s[i]=='e')
            {
                answer=(checkdouble(s, l, i, false) && checkdouble(s, i+1, r, true));
                return answer;
            }
        answer=checkdouble(s,l,r, false);
        return answer;
        
    }
};