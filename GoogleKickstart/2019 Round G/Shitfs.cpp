#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;
long long h;
long long ans = 0;

void dfs(int day, long long ah, long long bh, vector<long long> &a, vector<long long> &b) {
    if (ah >= h && bh >= h) {
        ans += pow(3, n - day);
        return;
    }
    
    if (ah + a[n]-a[day]<h || bh+b[n]-b[day]<h)
        return;

    if (day == n) {
        return;
    }

    dfs(day + 1, ah + a[day + 1] - a[day], bh + b[day + 1] - b[day], a, b);
    dfs(day + 1, ah + a[day + 1] - a[day], bh, a, b);
    dfs(day + 1, ah, bh + b[day + 1] - b[day], a, b);
}

void solution() {
    cin >> n >> h;
    ans = 0;
    vector<int> a(n), b(n);
    vector<long long> sa(n + 1, 0), sb(n + 1, 0);


    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sa[i + 1] = sa[i] + a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sb[i + 1] = sb[i] + b[i];
    }

    dfs(0, 0, 0, sa, sb);
    cout << ans << endl;
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