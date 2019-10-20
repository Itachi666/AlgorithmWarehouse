class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> f;
        vector<string> answer;
        sort(folder.begin(), folder.end());
        
        for (auto s:folder) {
            bool k=true;
            //cout<<s<<endl;
            for (int i=1;i<=s.length();i++) {
                if (s[i]=='/' || i==s.length()) {
                    //cout<<s.substr(0,i)<<endl;
                    if (f.find(s.substr(0,i))!=f.end()) {
                        k=false;
                        break;
                    }
                }
            }
            if (k) {
                f.insert(s);
                answer.push_back(s);
            }
        }
        
        return answer;
    }
};