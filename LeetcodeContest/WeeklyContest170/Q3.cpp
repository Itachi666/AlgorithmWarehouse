class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=watchedVideos.size();
        map<string, int> video;
        vector<string> ans;
        
        queue<int> person, lev;
        person.push(id);
        lev.push(0);
        
        vector<bool> used(n, false);
        used[id]=true;
        int l=0;
        while (!person.empty()) {
            if (l!=lev.front()) {
                if (l==level)
                    break;
                l=lev.front();
                video.clear();
            }
            
            int p=person.front();
            person.pop();
            lev.pop();
            
            for (auto& s:watchedVideos[p]) {
                // if (l==level)
                //     cout<<s<<' ';
                video[s]++;
            }
            // cout<<endl;
            
            for (int i=0;i<friends[p].size();i++)
                if (!used[friends[p][i]]) {
                    person.push(friends[p][i]);
                    used[friends[p][i]]=true;
                    lev.push(l+1);
                }
        }
        
        // for (auto& t:video)
        //     cout<<t.first<<' '<<t.second<<endl;
        
        map<int, set<string>> kkv;
        kkv.clear();
        
        for (auto& t:video)
            kkv[t.second].insert(t.first);
        
        for (auto& k:kkv)
            for (auto& v:k.second)
                ans.push_back(v);
        
        return ans;
    }
};