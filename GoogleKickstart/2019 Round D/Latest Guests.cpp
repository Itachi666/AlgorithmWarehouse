#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void Solution() {
    int n, m, g;
    cin >> n >> g >> m;

    vector<int> c(n + 1, 0);
    vector<unordered_set<int>> consulate(n + 1, unordered_set<int>());

    int round = m / n;
    int r = m % n;

    vector<pair<int, int>> clock, anticlock;
    unordered_map<int, int> muti, clp, anticlp;

    for (int i = 0; i < g; i++) {
        int h;
        char dir;
        cin >> h >> dir;
        h--;
        if (dir == 'C') {
            if (clp.find(h)==clp.end()) {
                muti[i] = i;
                clp[h]=i;
                clock.emplace_back(h, i);
            }
            else
                muti[i]=clp[h];
        } else {
            if (anticlp.find(h)==anticlp.end()) {
                muti[i] = i;
                anticlp[h]=i;
                anticlock.emplace_back(h, i);
            }
            else
                muti[i]=anticlp[h];
        }
    }
    anticlp.clear();
    clp.clear();
    sort(clock.begin(), clock.end());
    sort(anticlock.begin(), anticlock.end());

    for (auto &i : clock) {
        i.first = (i.first + r) % n;
    }
    for (auto &i : anticlock) {
        i.first = (i.first + n - r) % n;
    }
    int num = clock.size();
    for (int p = 0; p < num; p++) {
        int count = m;
        int &tt = clock[p].first;
        if (count == c[tt]) {
            consulate[tt].insert(clock[p].second);
        } else if (count > c[tt]) {
            c[tt] = count;
            consulate[tt].clear();
            consulate[tt].insert(clock[p].second);
        }

        count = m - 1;
        for (int t = (tt - 1 + n) % n;
             count >= 0 && t != clock[(p + num - 1) % num].first; t = (t - 1 + n) % n) {
            if (count == c[t]) {
                consulate[t].insert(clock[p].second);
            } else if (count > c[t]) {
                c[t] = count;
                consulate[t].clear();
                consulate[t].insert(clock[p].second);
            }
            count--;
        }
    }

    num = anticlock.size();
    for (int p = 0; p < num; p++) {
        int count = m;
        int &tt = anticlock[p].first;
        if (count == c[tt]) {
            consulate[tt].insert(anticlock[p].second);
        } else if (count > c[tt]) {
            c[tt] = count;
            consulate[tt].clear();
            consulate[tt].insert(anticlock[p].second);
        }

        count = m - 1;
        for (int t = (tt + 1) % n;
             count >= 0 && t != anticlock[(p + 1) % num].first; t = (t + 1) % n) {
            if (count == c[t]) {
                consulate[t].insert(anticlock[p].second);
            } else if (count > c[t]) {
                c[t] = count;
                consulate[t].clear();
                consulate[t].insert(anticlock[p].second);
            }
            count--;
        }
    }


    vector<int> guests(g, 0);

    for (int i = 0; i < n; i++) {
        for (auto &it:consulate[i])
            guests[it]++;
    }

//    for (int i = 0; i < n; i++) {
//        cout << i << ':';
//        for (auto &it:consulate[i])
//            cout << it << ' ';
//        cout << endl;
//    }
//
//    for (int i = 0; i < g; i++)
//        cout << muti[i] << ' ';
//    cout << endl;

    for (int i = 0; i < g; i++)
        cout << guests[muti[i]] << ' ';
    cout << endl;
}

int main() {
    // freopen("1.in", "r", stdin);
    int T;
    cin >> T;

    for (int TIM = 1; TIM <= T; TIM++) {
        cout << "Case #" << TIM << ": ";
        Solution();
    }

    return 0;
}