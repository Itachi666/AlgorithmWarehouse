#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 1e9 + 5;

vector<vector<int>> e;
vector<int> b;
vector<int> father;

void trans2Tree(int x, int fa) {
    father[x] = fa;
    for (auto i:e[x])
        if (i != fa)
            trans2Tree(i, x);
}

vector<vector<ll>> dp;

void search(int x) {
    if (e[x].empty()) {
        dp[x][0] = 0;
        dp[x][1] = b[x];
        dp[x][2] = INT64_MIN;
    } else {
        for (auto child:e[x])
            search(child);

        ll Max = INT64_MIN;
        dp[x][0] = 0;
        dp[x][1] = b[x];
        dp[x][2] = b[x];
        for (auto child:e[x]) {
            dp[x][0] += max(dp[child][0], dp[child][2]);
            dp[x][1] += max(dp[child][0] + b[child], max(dp[child][1], dp[child][2]));
            dp[x][2] += max(dp[child][0], max(dp[child][1], dp[child][2]));
            Max = max(Max, dp[child][1] - max(dp[child][0], dp[child][2]));
        }
        //cout<<x<<' '<<Max<<endl;
        if (Max<0)
            dp[x][2] += Max;
    }
}

void solution() {
    int V = 0;
    cin >> V;
    b.clear();
    b.resize(V);
    for (auto &x:b)
        cin >> x;
    e.clear();
    e.resize(V);
    for (int i = 0; i < V - 1; i++) {
        int x, y;
        cin >> x >> y;
        e[x - 1].emplace_back(y - 1);
        e[y - 1].emplace_back(x - 1);
    }
    father.clear();
    father.resize(V, -1);
    trans2Tree(0, -1);

    dp.clear();
    dp.resize(V, vector<ll>(3, 0));

    for (int i = 0; i < V; i++)
        e[i].clear();
    for (int i = 0; i < V; i++)
        if (father[i]!=-1)
            e[father[i]].emplace_back(i);

    search(0);

//    for (int i=0;i<V;i++) {
//        printf("%d: ", i);
//        for (int j=0;j<3;j++)
//            cout<<dp[i][j]<<' ';
//        cout<<endl;
//    }

    cout << max(dp[0][0], max(dp[0][1], dp[0][2])) << endl;
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