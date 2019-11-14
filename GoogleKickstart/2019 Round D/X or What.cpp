#include <bits/stdc++.h>

using namespace std;

using ll = long long;
bool odd[1024] = {false};

void setnum() {
    for (int i = 0; i < 1024; i++) {
        int t = 0;
        int x = i;
        while (x != 0) {
            t += x % 2;
            x /= 2;
        }
        odd[i] = t % 2;
    }
}

void Solution() {
    int n, q, ans = 0, count = 0;
    cin >> n >> q;
    vector<int> a(n, 0);
    set<int> s;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (odd[a[i]])
            s.insert(i);
    }

    for (; q > 0; q--) {
        int p = 0, v = 0;
        cin >> p >> v;
        int tmp = a[p];
        a[p]=v;

        if (odd[tmp])
            s.erase(p);

        if (odd[v])
            s.insert(p);

        if (s.size()%2==0)
            ans=n;
        else {
            ans = max(n - (*s.begin() + 1), *(--s.end()));
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    // freopen("1.in", "r", stdin);
    setnum();
    int T;
    cin >> T;

    for (int TIM = 1; TIM <= T; TIM++) {
        cout << "Case #" << TIM << ": ";
        Solution();
    }

    return 0;
}