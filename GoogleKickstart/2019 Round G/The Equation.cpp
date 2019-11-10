#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void calculateBin(long long x, vector<int> &nums) {
    long long Big = pow(2, 50);
    int i = 50;
    while (x) {
        if (x >= Big) {
            x -= Big;
            nums[i] += 1;
        }
        Big /= 2;
        i--;
    }
}

void solution() {
    long long n, m;
    long long sum = 0;
    long long ans = 0;
    cin >> n >> m;

    vector<int> nums(55, 0);
    vector<long long> min_num(55, 0);


    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        calculateBin(x, nums);
    }
    long long Big = 1;
    for (int i = 0; i <= 50; i++) {
        min_num[i + 1] = min_num[i] + Big * min((long long) nums[i], n - nums[i]);
        Big *= 2;
    }

    Big = pow(2, 50);
    for (int i = 50; i >= 0; i--) {
        if (sum + Big * (n - nums[i]) + min_num[i] <= m) {
            sum += Big * (n - nums[i]);
            ans += Big;
        } else if (sum + Big * nums[i] + min_num[i]<= m) {
            sum += Big * nums[i];
        } else {
            cout << -1 << endl;
            return;
        }
        Big /= 2;
    }

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