#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n,h;
int ans=0;
void dfs(int day, int ah, int bh, vector<int>& a, vector<int>& b) {
    //printf("%d %d %d %d\n", day,ah,bh, ans);
//    if (ah>=h && bh>=h) {
//        ans+=pow(3,n-day);
//        return;
//    }

    if (day==n) {
        if (ah>=h && bh>=h)
            ans++;
        return;
    }

    dfs(day+1, ah+a[day], bh, a,b);
    dfs(day+1, ah, bh+b[day], a,b);
    dfs(day+1, ah+a[day], bh+b[day], a,b);
}

void solution() {
    cin>>n>>h;
    ans=0;
    vector<int> a(n);
    vector<int> b(n);
    for (int& x:a)
        cin>>x;

    for (int& x:b)
        cin>>x;

    dfs(0,0,0,a,b);
    cout<<ans<<endl;
}

int main() {
    freopen("1.in", "r", stdin);
    int T;
    cin >> T;

    for (int TIM = 1; TIM <= T; TIM++) {
        cout << "Case #" << TIM << ": ";
        solution();
    }

    return 0;
}