//
// Created by Niujx on 2019/11/24.
//

using ll = long long;

ll quickPow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b /= 2;
    }
    return ans;
}
