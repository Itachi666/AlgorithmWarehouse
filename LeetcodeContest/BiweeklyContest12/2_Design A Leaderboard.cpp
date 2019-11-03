class Leaderboard {
public:
    map<int, int> id_s, s;
    
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (id_s.find(playerId)==id_s.end())
            id_s[playerId]=0;
        
        int& t=id_s[playerId];
        s[t]--;
        if (s[t]==0)
            s.erase(t);
        t+=score;
        s[t]++;
    }
    
    int top(int K) {
        int count=0;
        for (auto i=s.rbegin();i!=s.rend();i++)
        {
            if (K>=i->second) {
                count+=i->first*i->second;
                K-=i->second;
            } else {
                count+=i->first*K;
                K=0;
            }
            if (K==0)
                break;
        }
        return count;
    }
    
    void reset(int playerId) {
        int& t=id_s[playerId];
        s[t]--;
        if (s[t]==0)
            s.erase(t);
        id_s.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */