class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int dp[1002][1002]={0};
        int n=s.length();
        
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                dp[i][j]=1001;
        
        
        for (int i=0;i<s.length();i++) {
            dp[i][i]=0;
            if (i!=0 && s[i]==s[i-1])
                dp[i-1][i]=0;
        }

        for (int length=1;length<n;length++)
            for (int i=0;i<n-length;i++) {
                int j=i+length;
                
                //cout<<i<<' '<<j<<endl;
                dp[i][j]=min(dp[i+1][j], dp[i][j-1])+1;

                if (s[i]==s[j])
                    dp[i][j]=min(dp[i][j], dp[i+1][j-1]);
                
                if (length==1 && s[i]==s[j])
                    dp[i][j]=0;
            }

        return (dp[0][n-1]<=k);
    }
};