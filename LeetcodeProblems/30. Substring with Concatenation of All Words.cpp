// Runtime: 268 ms
// Memory Usage: 29.8 MB

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;
        if (words.size()==0 || s=="")
            return answer;
        int wordlen=words[0].length();
        int n=wordlen*words.size();

        unordered_map<string, int> t;
        for (int i=0;i<words.size();i++)
            if (t.find(words[i])!=t.end())
                t[words[i]]++;
            else
                t[words[i]]=1;

        for (int k=0;k<wordlen;k++) {
            unordered_map<string, int> m;
            int i=k, j=k;
            while (i<=(int)(s.length())-n) {
                //cout<<i<<' '<<s.length()-n<<endl;
                int p=i+wordlen;
                for (;j-i<n;j+=wordlen) {
                    if (t.find(s.substr(j, wordlen))==t.end())
                        p=j+wordlen;
                    m[s.substr(j, wordlen)]++;
                }

                if (p==i+wordlen) {
                    bool check=true;
                    //cout<<i<<' '<<j<<endl;
                    for (auto it:words) {
                        //cout<<it<<' '<<m[it]<<' '<<t[it]<<endl;
                        if (m[it]!=t[it])
                            check=false;
                    }
                    if (check) {
                        answer.push_back(i);
                    }
                }

                for (int l=i;l<p;l+=wordlen)
                    if (--m[s.substr(l, wordlen)]==0)
                        m.erase(s.substr(l, wordlen));
                i=p;
            }

        }
        return answer;
    }
};