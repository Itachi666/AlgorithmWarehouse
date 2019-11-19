#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 1e9 + 5;

void merge(set<pair<int, int>> &s, int x) {
    auto l = s.upper_bound(make_pair(x, x));
    auto r = l--;

    //printf("l:[%d, %d], r:[%d, %d]\n", l->first, l->second, r->first, r->second);

    if (l->second == x - 1) {
        if (r->first == x + 1) {
            s.insert(make_pair(l->first, r->second));
            s.erase(r);
        } else {
            s.insert(make_pair(l->first, x));
        }
        s.erase(l);
    } else if (r->first == x + 1) {
        s.insert(make_pair(x, r->second));
        s.erase(r);
    } else
        s.insert(make_pair(x, x));
}

void r_out(vector<set<pair<int, int>>> &s, int x) {
    printf("R[%d]: ", x);
    for (auto kky:s[x])
        printf("[%d, %d],", kky.first, kky.second);
    cout << endl;
}

void c_out(vector<set<pair<int, int>>> &s, int x) {
    printf("C[%d]: ", x);
    for (auto kky:s[x])
        printf("[%d, %d],", kky.first, kky.second);
    cout << endl;
}


vector<set<pair<int, int>>> R, C;

void Solution() {
    int n, r, c, sr, sc;
    cin >> n >> r >> c >> sr >> sc;
    R.clear();
    C.clear();
    R.resize(r + 1);
    C.resize(c + 1);

    for (int i = 1; i <= r; i++) {
        R[i].insert(make_pair(0, 0));
        R[i].insert(make_pair(c + 1, c + 1));
    }

    for (int i = 1; i <= c; i++) {
        C[i].insert(make_pair(0, 0));
        C[i].insert(make_pair(r + 1, r + 1));
    }

    int x = sr, y = sc;
    merge(R[x], y);
    merge(C[y], x);
    char Dir;
    for (; n > 0; n--) {
//        printf("x=%d y=%d\n", x, y);
//        r_out(R, x);
//        c_out(C, y);

        cin >> Dir;
        if (Dir == 'E') {
            y = y + 1;
            auto left = R[x].upper_bound(make_pair(y, y));
            auto right = left--;

            if (left->second >= y)
                y = left->second + 1;
        }

        if (Dir == 'W') {
            y = y - 1;
            auto left = R[x].upper_bound(make_pair(y, y));
            auto right = left--;

            if (right->first <= y)
                y = right->first - 1;
            else if (left->second >= y)
                y = left->first - 1;
        }

        if (Dir == 'S') {
            x = x + 1;
            auto left = C[y].upper_bound(make_pair(x, x));
            auto right = left--;

            if (left->second >= x)
                x = left->second + 1;
        }

        if (Dir == 'N') {
            x = x - 1;
            auto left = C[y].upper_bound(make_pair(x, x));
            auto right = left--;

            // printf("l:[%d, %d], r:[%d, %d]\n", left->first, left->second, right->first, right->second);

            if (right->first <= x)
                x = right->first - 1;
            else if (left->second >= x)
                x = left->first - 1;
        }

        merge(R[x], y);
        merge(C[y], x);
    }

    cout << x << ' ' << y << endl;
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