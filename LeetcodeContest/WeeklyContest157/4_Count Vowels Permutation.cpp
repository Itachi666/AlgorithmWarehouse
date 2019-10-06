class Solution {
public:
    int countVowelPermutation(int n) {
        const int T=1000000007;
        vector<long long> a,e,i,o,u;
        a.push_back(1);
        e.push_back(1);
        i.push_back(1);
        o.push_back(1);
        u.push_back(1);
        
        for (int j=1;j<n;j++) {
            a.push_back((e[j-1] + i[j-1] + u[j-1])%T);
            e.push_back((a[j-1] + i[j-1])%T);
            i.push_back((e[j-1] + o[j-1])%T);
            o.push_back(i[j-1]%T);
            u.push_back((o[j-1] + i[j-1])%T);
        }
        
        int ans=(a[n-1]+e[n-1]+i[n-1]+o[n-1]+u[n-1])%T;
        
        return ans;
    }
};