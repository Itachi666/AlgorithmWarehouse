#include <bits/stdc++.h>
#include "src/TempAlg/Prime.h"
#include "src/Matrix.h"
#include "src/Tree/Tree.h"

using namespace std;
using ll = long long;

vector<int> stringToIntegerVector(string input);
ll quickPow(ll a, ll b);
struct ListNode {
    explicit ListNode(int x);
};

struct Listnode {
    int val;
    Listnode *next, *before;
    explicit Listnode(int x): val(x), next(NULL), before(NULL) {};
};

class Solution {
public:
    int gcd(int x, int y) {
        return (x%y)? gcd(y, x%y) : y;
    }

    bool isGoodArray(vector<int>& nums) {
        return false;
    }
};

void Leetcode_cin() {
    freopen("1.in", "r", stdin);
    string line;
    while (getline(cin, line)) {
        getline(cin, line);

        vector<int> v = stringToIntegerVector(line);
        cout<<endl<<line<<endl;

        Solution().isGoodArray(v);
        cout<<Solution().gcd(56,31)<<endl;

    }
}

void solution() {
    int n,m,ans=-1;
    cin>>n>>m;
    vector<int> a(n);
    for (int& x:a)
        cin>>x;

    for (int i=0;i<=128;i++)
    {
        int t=0;
        for (int j=0;j<n;j++)
            t+=a[j]^i;
        //cout<<i<<' '<<t<<endl;

        if (t<=m)
            ans=max(i,ans);
    }
    cout<<ans<<endl;


}

void Kickstart_cin() {
    freopen("1.in", "r", stdin);
    int T;
    cin >> T;

    for (int TIM = 1; TIM <= T; TIM++) {
        cout << "Case #" << TIM << ": ";
        solution();
    }
}

struct cmp {
    bool operator ()(const string& s1, const string& s2) {
        return s1<s2;
    }
};

int main() {
    vector<string> s;
    for (int i=1;i<26;i++)
        s.push_back(to_string(i));
    sort(s.begin(), s.end(), cmp());
    priority_queue<string, vector<string>, cmp> t;
    for (auto& t:s)
        cout<<t<<' ';

/*    vector<vector<int>> m(10,vector<int>(10, 1));

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> q;

    Matrix<int> base(m);
    base.display();

    base=base^3;
    base.display();

    cout<<quickPow(2,32);*/

    return 0;
}