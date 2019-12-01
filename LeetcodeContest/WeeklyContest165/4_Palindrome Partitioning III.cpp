class Solution {
public:
    int minreplace(string s, int l, int r) {
        int count=0;
        
        while (l<r) {
            if (s[l]!=s[r])
                count++;
            l++;
            r--;
        }
        
        return count;
    }
    
    int palindromePartition(string s, int k) {
        vector<vector<int>> dp(s.size()+1, vector<int >(k+1, 0x7ffffff));
        
        dp[0][0]=0;
        
        for (int i=0;i<s.size();i++) {
            
            dp[i][0]=minreplace(s, 0, i);
            
            for (int j=1;j<=k && j<=i;j++) {
                
                
                for (int t=i-1;t>=0;t--)
                    dp[i][j]=min(dp[i][j], dp[t][j-1]+minreplace(s, t+1, i));
                
            }
        }
        
//         for (int i=0;i<s.size();i++) {
//             for (int j=0;j<=k && j<=i;j++) 
//                 cout<<dp[i][j]<<' ';
//             cout<<endl;
//         }
        
        return dp[s.size()-1][k-1];
    }
};