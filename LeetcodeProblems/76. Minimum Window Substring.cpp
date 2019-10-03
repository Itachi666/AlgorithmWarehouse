// Runtime: 8 ms
// Memory Usage: 11 MB

class Solution {
public:
    string minWindow(string s, string t) {     
        short num[128]={0}, a[128]={0}; 
        queue<short> q;
        
        for (int i=0;i<t.length();i++)
        {
            num[t[i]]++;
            a[t[i]]=0;
        }
        int l=0,r=0,fl=0,fr=0;
        
        while (!num[s[l]] && l<s.length())
            l++;
        r=l;
        
        int k=0;
        while (k<t.length() && r<s.length())
        {
            if (num[s[r]])
            {
                q.push(r);
                a[s[r]]+=1;
                
                if (a[s[r]]<=num[s[r]])
                    k++;
                
                if (s[q.front()]==s[r])
                {
                    while (a[s[l]]>num[s[l]]){
                        a[s[l]]-=1;
                        q.pop();
                        l=q.front();
                    }
                }
                //cout<<s.substr(l,r-l+1)<<' '<<k<<endl;
            }
            r++;
        }
        
        if (k<t.length())
            return "";
        r--;
        fl=l;
        fr=r;
        
        for (int i=r+1;i<s.length();i++)
            if (num[s[i]])
            {
                q.push(i);
                a[s[i]]+=1;
    
                if (s[q.front()]==s[i])
                {
                    do {
                        a[s[l]]-=1;
                        q.pop();
                        l=q.front();
                    }while (a[s[l]]>num[s[l]]);
                    r=i;
                    
                    if (fr-fl>r-l)
                    {
                        fr=r;
                        fl=l;
                    }
                }
            }
        
        return s.substr(fl,fr-fl+1);
    }
};