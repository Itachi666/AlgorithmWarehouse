class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<char, int> letter;
        unordered_map<string, int> word;
        
        int n=s.length(), ans=0;
        
        for (int l=minSize; l<=minSize; l++) {
            letter.clear();
            int i=0, j=i+l;
            
            for (int k=i;k<j;k++)
                letter[s[k]]++;
            
            if (letter.size()<=maxLetters) {
                word[s.substr(i, l)]++;
                ans=max(ans, word[s.substr(i, l)]);
                // cout<<s.substr(i, l)<<endl;
            }
            
                
            
            while (j<n) {
                letter[s[i]]--;
                if (letter[s[i]]==0)
                    letter.erase(s[i]);
                i++;
                
                letter[s[j]]++;
                j++;
                
                if (letter.size()<=maxLetters) {
                    word[s.substr(i, l)]++;
                    
                    ans=max(ans, word[s.substr(i, l)]);
                    // cout<<s.substr(i, l)<<endl;
                }
            }
        }
        
        return ans;
    }
};