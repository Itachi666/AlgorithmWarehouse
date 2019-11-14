#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 1e9 + 5;

vector<int> father;

int find(int x) {
    return father[x] == x ? x : father[x] = find(father[x]);
}

void solution() {
    int m, n;
    cin >> n >> m;

    father.clear();
    father.resize(n, 0);
    for (int i = 0; i < n; i++)
        father[i] = i;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (find(x - 1) != find(y - 1))
            father[find(y - 1)] = find(x - 1);
    }
    int sugar = 0;
    map<int, int> black;

    for (int i = 0; i < n; i++)
        black[find(i)]++;

    for (auto b:black)
        sugar += b.second - 1;

    sugar += int(black.size() - 1) * 2;

    cout << sugar << endl;
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