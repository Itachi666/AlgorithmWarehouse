class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        vector<char> m(27, 0);
        
        for (int i=1;i<=26;i++)
            m[i]='a'-1+i;
        
        for (int i=0;i<s.length();i++) {
            if (i<s.length()-2 && s[i+2]=='#') {
                // cout<<s.substr(i,2)<<endl;
                ans+=m[stoi(s.substr(i,2))];
                i+=2;
            }
            else
                ans+=m[s[i]-'0'];
        }
        
        return ans;
    }
};