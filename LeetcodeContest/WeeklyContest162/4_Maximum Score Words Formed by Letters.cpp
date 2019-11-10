class Solution {
public:
    int ans=0;
    
    void dfs(int n, int g, int ln, vector<string>& words, vector<short> letter, vector<int>& score) {
        if (n==words.size()) {
            //cout<<g<<endl;
            ans=max(ans, g);
            return;
        }
        
        dfs(n+1, g, ln, words, letter, score);
        
        if (ln>=words[n].size()) {
            int sc=0;
            for (int i=0;i<words[n].size();i++) {
                char& t=words[n][i];
                sc+=score[t-'a'];
                letter[t-'a']--;
                ln--;

                if (letter[t-'a']<0)
                    return;
            }

            dfs(n+1, g+sc, ln, words, letter, score);
        }
        
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<short> letter(26,0);
        for (auto le:letters) 
            letter[le-'a']++;
        
        dfs(0, 0, letters.size(), words, letter, score);
        
        return ans;
    }
};