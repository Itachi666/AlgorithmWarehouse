// Runtime: 4 ms
// Memory Usage: 9.1 MB

class Solution {
public:
    string getspace(int t)
    {
        string s;
        for (int i=0;i<t;i++)
            s+=' ';
        return s;
    }
    
    string combine(int l, int r,const vector<string>& words,const int& maxWidth)
    {
        //cout<<l<<'-'<<r<<' ';
        int len=0;
        for (int i=l;i<r;i++)
            len+=words[i].length();
        int n=r-l-1;
        string s;
        if (n==0)
        {
            s+=words[l];
            s+=getspace(maxWidth-s.length());
            return s;
        }
        for (int i=l;i<r-1;i++)
        {
            s+=words[i];
            s+=getspace((maxWidth-len)/n + int(i-l<(maxWidth-len)%n));
        }
        s+=words[r-1];
        return s;
        
    }
    
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;
        int l=0,len=0;
        for (int i=0;i<words.size();i++)
        {
            len+=words[i].length();
            if (len>maxWidth)
            {
                answer.push_back(combine(l,i,words,maxWidth));
                l=i;
                len=words[i].length();
            }
            len++;
        }
        if (l<words.size())   
        {
            string s;
            for (int i=l;i<words.size()-1;i++)
                s+=words[i]+" ";
            s+=words[words.size()-1];
            s+=getspace(maxWidth-s.length());
            answer.push_back(s);
        }
    
        return answer;
    }
};