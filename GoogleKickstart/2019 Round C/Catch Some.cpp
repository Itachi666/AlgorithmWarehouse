#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 1e9 + 5;

typedef struct {
    int p, c;
} Dog;

void Solution() {
    int n, k;
    cin >> n >> k;
    vector<Dog> dogs(n);
    vector<int> color;
    map<int, vector<int>> c2p;
    for (auto &d:dogs)
        cin >> d.p;
    for (auto &d:dogs) {
        cin >> d.c;
        if (c2p.find(d.c) == c2p.end()) {
            color.emplace_back(d.c);
            c2p.insert(make_pair(d.c, vector<int>()));
        }

        c2p[d.c].push_back(d.p);
    }
    for (auto c:color) {
//        cout << c << ": ";
        sort(c2p[c].begin(), c2p[c].end());
//        for (auto t:c2p[c])
//            cout << t << ' ';
//        cout << endl;
    }

    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(k + 1, make_pair(INF, INF)));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = make_pair(0, 0);
    }


    for (int i = 1; i <= color.size(); i++) {
        int &col = color[i - 1];
//        cout << col << ": ";
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int num = 1; num <= j && num <= c2p[col].size(); num++) {
                dp[i][j].first = min(dp[i][j].first, dp[i - 1][j - num].first + c2p[col][num - 1] * 2);
                dp[i][j].second = min(dp[i][j].second, dp[i - 1][j - num].first + c2p[col][num - 1]);
                dp[i][j].second = min(dp[i][j].second, dp[i - 1][j - num].second + c2p[col][num - 1] * 2);
            }


//            cout << dp[i][j].second << ' ';
        }

//        cout << endl;
    }

    cout << dp[(int) color.size()][k].second << endl;
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