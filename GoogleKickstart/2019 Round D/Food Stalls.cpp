#include <bits/stdc++.h>

using namespace std;

using ll = long long;

typedef struct {
    ll cost, meter;
} Stall;

void Solution() {
    int k, n;
    cin >> k >> n;
    vector<int> x(n), c(n);
    vector<ll> v(n);
    vector<Stall> stalls(n);
    for (auto &i:x)
        cin >> i;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        stalls[i].cost = c[i];
        stalls[i].meter = x[i];
    }
    sort(stalls.begin(), stalls.end(), [](const Stall &a, const Stall &b) { return a.meter < b.meter; });
    for (int i = 0; i < n; i++)
        v[i] = stalls[n - 1].meter - stalls[i].meter + stalls[i].cost;

    vector<ll> left(n), right(n);
    priority_queue<ll, vector<ll>, less<>> maxHeap;
    ll sumHeap = 0;
    for (int i = 0; i < k / 2; i++) {
        maxHeap.push(v[i]);
        sumHeap += v[i];
    }
    ll &xn = stalls[n - 1].meter;

    for (int i = k / 2; i < n - (k - k / 2); i++) {
        left[i] = sumHeap - (ll)(k / 2) * (xn - stalls[i].meter);
        if (!maxHeap.empty() && v[i] < maxHeap.top()) {
            sumHeap -= maxHeap.top();
            maxHeap.pop();
            maxHeap.push(v[i]);
            sumHeap += v[i];
        }
//        cout << left[i] << ' ';
    }
//    cout << endl;
    maxHeap = priority_queue<ll, vector<ll>, less<>>();
    sumHeap = 0;
    for (int i = 0; i < n; i++)
        v[i] = stalls[i].meter - stalls[0].meter + stalls[i].cost;
    for (int i = n - 1; i >= n - (k - k / 2); i--) {
        maxHeap.push(v[i]);
        sumHeap += v[i];
    }
    ll &x0 = stalls[0].meter;
    for (int i = n - (k - k / 2) - 1; i >= k / 2; i--) {
        right[i] = sumHeap - (ll)(k - k / 2) * (stalls[i].meter - x0);
        if (!maxHeap.empty() && v[i] < maxHeap.top()) {
            sumHeap -= maxHeap.top();
            maxHeap.pop();
            maxHeap.push(v[i]);
            sumHeap += v[i];
        }
    }
    ll ans = INT64_MAX;
    for (int i = k / 2; i < n - (k - k / 2); i++) {
//        cout << right[i] << ' ';
        ans = min(ans, left[i] + right[i] + stalls[i].cost);
    }


    cout << ans << endl;
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