#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 1e9 + 5;

#define random(a, b) (rand() % ((b) -(a)) +(a))
namespace Prime {
    ll power_mod(ll x, ll n, ll mod) {
        ll ret = 1;
        while (n) {
            if (n & 1) ret = x * ret % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return ret;
    }

    ll mulmod(ll x, ll y, ll n) {
        return x * y % n;
    }

    bool witness(ll a, ll n, ll u, ll t) {
        ll x0 = power_mod(a, u, n), x1;
        for (int i = 1; i <= t; ++i) {
            x1 = mulmod(x0, x0, n);
            if (x1 == 1 && x0 != 1 && x0 != n - 1)
                return false;
            x0 = x1;
        }
        if (x1 != 1)return false;
        return true;
    }

    bool miller_rabin(ll n, int times = 20) {
        if (n < 2)return false;
        if (n == 2)return true;
        if (!(n & 1))return false;
        ll u = n - 1, t = 0;
        while (u % 2 == 0) {
            t++;
            u >>= 1;
        }
        while (times--) {
            ll a = random(1, n - 1);
            //if(a == 0)std::cout << a << " "<<n<< " "<<u<<" " << t<<'\n';
            if (!witness(a, n, u, t))return false;
        }
        return true;
    }
};

bool check(int x) {
    int num2 = 0;
    while (x % 2 == 0) {
        num2++;
        x /= 2;
        if (num2 >= 4) return false;
    }

    if (num2 == 3) return x == 1;
    if (num2 == 2) return (x == 1) ? true : Prime::miller_rabin(x);
    if (num2 == 1) return true;
    if (num2 == 0) return (x == 1) ? true : Prime::miller_rabin(x);
    return false;
}

void solution() {
    int L, R;
    cin >> L >> R;
    int ans = 0;

    for (int i = L; i <= R; i++) {
        ans += check(i);
    }
    cout << ans << endl;
}

int main() {
    // freopen("1.in", "r", stdin);
    int T;
    cin >> T;

    for (int TIM = 1; TIM <= T; TIM++) {
        cout << "Case #" << TIM << ": ";
        solution();
    }

    return 0;
}