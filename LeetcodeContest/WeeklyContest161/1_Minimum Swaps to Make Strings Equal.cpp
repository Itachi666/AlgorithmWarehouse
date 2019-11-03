class Solution {
public:
    int minimumSwap(string s1, string s2) {
        map<char, int> a,b;
        int answer=0;
        
        if (s1.length()!=s2.length())
            return -1;
        
        int last=-1;
        
        for (int i=0;i<s1.length();i++) {
            if (s1[i]!=s2[i]) {
                a[s1[i]]++;
            }
        }
        
        if ((a['x']+a['y'])%2)
            return -1;
        
        answer=a['x']/2+a['y']/2;
        a['x']%=2;
        a['y']=a['y']%2;
        
        if (a['x']==1)
            answer+=2;
        
        return answer;
    }
};