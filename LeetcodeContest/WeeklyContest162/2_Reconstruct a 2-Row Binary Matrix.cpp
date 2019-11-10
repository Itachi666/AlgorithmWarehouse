class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n=colsum.size();
        vector<int> a(n,0), b(n,0);
        
        for (int i=0;i<n;i++) {
            if (colsum[i]==2) {
                a[i]=1;
                b[i]=1;
                upper--;
                lower--;
                
                if (upper<0 || lower<0)
                    return vector<vector<int>>{};
            }
            
            if (colsum[i]==1) {
                if (upper<lower) {
                    b[i]=1;
                    lower--;
                    
                    if (lower<0)
                        return vector<vector<int>>{};
                } else {
                    a[i]=1;
                    upper--; 
                    
                    if (upper<0)
                        return vector<vector<int>>{};
                }
            }
        }
        
        if (lower==0 && upper==0)
            return vector<vector<int>>{a,b};
        else 
            return vector<vector<int>>{};
    }
};