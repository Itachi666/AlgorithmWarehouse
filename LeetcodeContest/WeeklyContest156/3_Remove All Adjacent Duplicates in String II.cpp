class Solution {
public:
    string removeDuplicates(string s, int k) {
        //s.substr(0, i - k + 1)
        bool done=false;
        while (!done) {
            int count=1;
            done=true;
            for (int i=1;i<s.length();i++)
            {
                if (s[i]==s[i-1])
                    count++;
                else
                    count=1;
                    
                
                if (count==k) {
                    s=s.substr(0, i-k+1)+ s.substr(i+1);
                    done = false;
                }
            }
        }
        return s;
    }
};