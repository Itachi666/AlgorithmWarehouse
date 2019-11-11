#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 1e5 + 5;

int get(int l, int r, vector<int> &a) {
    int t = INF;
    map<int, int> m;
    for (int i = l; i <= r; i++) {
        m[a[i]]++;
    }
    for (auto it:m)
        t = min(t, r-l+1-it.second);
    return t;
}

void solution() {
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for (auto &x:a)
        cin >> x;
    int now = 0;
    for (int i = 0; i < n - 1; i++)
        if (a[i] != a[i + 1])
            now++;
    if (now <= K) {
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> R(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            R[i][j] = get(i, j, a);

    vector<vector<int>> dp(n, vector<int>(n, INF));

    for (int i = 0; i <= K; i++)
        dp[0][i] = 0;

    for (int i = 1; i < n; i++)
        dp[i][0] = R[0][i];

    for (int x = 0; x < n; x++)
        for (int k = 1; k <= K; k++) {
            for (int i = 0; i < x; i++)
                dp[x][k] = min(dp[x][k], dp[i][k - 1] + R[i + 1][x]);
        }

//    for (int x = 0; x < n; x++) {
//        for (int k = 0; k <= K; k++)
//            cout << dp[x][k] << ' ';
//        cout << endl;
//    }

    printf("%d\n", dp[n - 1][K]);
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