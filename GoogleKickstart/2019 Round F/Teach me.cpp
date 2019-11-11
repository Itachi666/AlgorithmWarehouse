#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 1e9 + 5;

unordered_map<ll, int> hashmap;

ll trans2ll(set<int> &bit) {
    ll k = 1, ans = 0;
    for (auto b:bit) {
        ans += b * k;
        k = k * 1001;
    }
    return ans;
}

set<int> get(set<int> &t, int x) {
    set<int> s;
    auto k = t.begin();
    while (x != 0) {
        if (x % 2)
            s.insert(*k);
        x /= 2;
        k++;
    }
    return s;
}

void solution() {
    ll answer = 0;
    int n, s;
    cin >> n >> s;
    vector<int> c(n);
    vector<set<int>> a(n, set<int>());

    hashmap.clear();

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        int k;
        for (int j = 0; j < c[i]; j++) {
            cin >> k;
            a[i].insert(k);
        }
        hashmap[trans2ll(a[i])]++;
    }

    for (int i = 0; i < n; i++) {
        int sum = n;
        for (int t = 1; t < pow(2, c[i]); t++) {
            set<int> k = get(a[i], t);
            ll num=trans2ll(k);

            if (hashmap.find(num)!=hashmap.end())
                sum-=hashmap[num];
        }
        answer+=sum;
    }

    cout << answer << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    int T;
    cin >> T;

    for (int TIM = 1; TIM <= T; TIM++) {
        cout << "Case #" << TIM << ": ";
        solution();
    }

    return 0;
}