#include <bits/stdc++.h>
#include "src/Prime.h"

using namespace std;

vector<int> stringToIntegerVector(string input);

class Solution {
public:
    int gcd(int x, int y) {
        return (x%y)? gcd(y, x%y) : y;
    }

    bool isGoodArray(vector<int>& nums) {
        return false;
    }
};

void Leetcode_cin() {
    freopen("1.in", "r", stdin);
    string line;
    while (getline(cin, line)) {
        getline(cin, line);

        vector<int> v = stringToIntegerVector(line);
        cout<<endl<<line<<endl;

        Solution().isGoodArray(v);
        cout<<Solution().gcd(56,31)<<endl;

    }
}

void solution() {
    int n,m,ans=-1;
    cin>>n>>m;
    vector<int> a(n);
    for (int& x:a)
        cin>>x;

    for (int i=0;i<=128;i++)
    {
        int t=0;
        for (int j=0;j<n;j++)
            t+=a[j]^i;
        //cout<<i<<' '<<t<<endl;

        if (t<=m)
            ans=max(i,ans);
    }
    cout<<ans<<endl;


}

void Kickstart_cin() {
    freopen("1.in", "r", stdin);
    int T;
    cin >> T;

    for (int TIM = 1; TIM <= T; TIM++) {
        cout << "Case #" << TIM << ": ";
        solution();
    }
}

int main() {
    Kickstart_cin();
    cout<<Prime::miller_rabin(1203487239841);
    return 0;
}