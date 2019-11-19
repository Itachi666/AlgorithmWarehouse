class Solution {
public:
    int numberOfWays(int num_people) {
        unsigned long long dp[1001]={0};
        dp[0]=1;
        dp[1]=1;
        const int MOD = 1e9+7;
        
        
        for (int i=2;i<=num_people/2;i++) {
            for (int j=2;j<=i*2;j+=2) {
                dp[i]=(dp[i]+dp[(j-2)/2]*dp[(i*2-j)/2]) % MOD;
                // cout<<j-2<<' '<<i*2-j<<endl;
            }
            // cout<<dp[i]<<endl;
        }
        
        return dp[num_people/2];
    }
};