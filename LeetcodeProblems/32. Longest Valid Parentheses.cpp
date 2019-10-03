// Runtime: 20 ms
// Memory Usage: 12.4 MB

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> P;
        stack<int> P_place;
        stack<int> r;
        map<int, int> last_r;
        int answer=0;
        
        for (int i=0;i<s.length();i++)
        {
            if (s[i]=='(')
            {
                P.push('(');
                P_place.push(i);
            }
            if (s[i]==')')
            {
                if (P.empty())
                {
                    last_r[i]=0;
                    r.push(i);
                    continue;
                }
                
                int k=P_place.top();
                
                P_place.pop();
                P.pop();
                //cout<<k<<endl;
                if (r.size()==0)
                    last_r[i]=1;
                else
                {
                    int lastp=r.top();
                    if (k<lastp)
                        last_r[i]=last_r[lastp]+1;
                    else
                        last_r[i]=1;
                }
                r.push(i);
                if (k!=0 && s[k-1]==')')
                    last_r[i]+=last_r[k-1];
                answer=max(answer,last_r[i]);
            }
        }
        return answer*2;
    }
};