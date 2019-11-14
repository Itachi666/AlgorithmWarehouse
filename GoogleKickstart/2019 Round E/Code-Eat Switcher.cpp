#include <bits/stdc++.h>

using namespace std;

using ll = long long;

typedef struct {
    ll code, eat;
    int id;
    bool result;
} Node;

int mid_find(int l, int r, vector<ll> &s, ll &target) {
    if (l == r)
        return l;
    int m = (r + l) / 2;

    if (s[m] < target)
        return mid_find(m + 1, r, s, target);
    else
        return mid_find(l, m, s, target);
}

void solution() {
    int day, s;
    cin >> day >> s;
    vector<pair<ll, ll>> slots(s);
    vector<ll> sumc(s, 0), sume(s, 0);
    for (int i = 0; i < s; i++) {
        cin >> slots[i].first >> slots[i].second;
    }

    sort(slots.begin(), slots.end(),
         [](const pair<ll, ll> &a, const pair<ll, ll> &b) { return a.first * b.second > a.second * b.first; });

    for (int i = 0; i < s; i++) {
        sumc[i + 1] = sumc[i] + slots[i].first;
        sume[i + 1] = sume[i] + slots[i].second;
    }

    vector<Node> requires(day);
    for (int i = 0; i < day; i++) {
        cin >> requires[i].code >> requires[i].eat;
        requires[i].id = i;
    }
    sort(requires.begin(), requires.end(), [](const Node &a, const Node &b) { return a.code < b.code; });

    for (auto &r:requires) {
        //while (k < s && sumc[k + 1] < r.code) k++;
        int k = mid_find(1, s + 1, sumc, r.code) - 1;

        if (k == s) {
            r.result = false;
            continue;
        }

        if (sume[s] - sume[k + 1] >= r.eat) {
            r.result = true;
            continue;
        } else {
            ll need_eat = r.eat - (sume[s] - sume[k + 1]);
            ll need_code = r.code - sumc[k];

            ll code = slots[k].first;
            ll eat = slots[k].second;
            r.result = (code - need_code) * eat >= need_eat * code;
        }
    }


    sort(requires.begin(), requires.end(), [](const Node &a, const Node &b) { return a.id < b.id; });
    for (auto re:requires)
        if (re.result)
            cout << 'Y';
        else
            cout << 'N';

    cout << endl;
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