#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main() {
    //freopen("1.in", "r", stdin);
    int T;
    cin>>T;

    int m,n,q,t;
    set<int> reader, page;

    for (int TIM=1;TIM<=T;TIM++) {
        cin>>n>>m>>q;
        long long answer=0;

        page.clear();
        reader.clear();

        for (int i=0;i<m;i++) {
            cin>>t;
            page.insert(t);
        }
        for (int i=0;i<q;i++) {
            cin>>t;
            reader.insert(t);
        }

        for (auto r:reader) {
            answer+=n/r;
        }

        for (auto p:page) {
            int i=0;
            for (auto r:reader)
                if (p%r==0)
                    i++;

            answer-=i;
        }
        
        cout << "Case #" << TIM << ": " << answer << endl;
    }

    return 0;
}