class Solution {
public:
    map<char,int> c[100001];

    bool check(int l, int r) {
        int q=c[r]['Q']-c[l-1]['Q'];
        int w=c[r]['W']-c[l-1]['W'];
        int e=c[r]['E']-c[l-1]['E'];
        int R=c[r]['R']-c[l-1]['R'];

        return (q==w && w==e && e==R);
    }

    int get(int l, int r, string s) {
        if (l>r)
            return 0;
        int t=(r-l+1)/4;
        //cout<<l<<' '<<r<<endl;
        map<char,int> m;

        m['Q']=c[r+1]['Q']-c[l]['Q'];
        m['W']=c[r+1]['W']-c[l]['W'];
        m['E']=c[r+1]['E']-c[l]['E'];
        m['R']=c[r+1]['R']-c[l]['R'];

        int i=l,j=l-1;
        int ans=100000;
        while (i<=r) {

            if (m['Q']<=t && m['W']<=t && m['E']<=t && m['R']<=t) {
                //cout<<i<<' '<<j<<endl;
                ans=min(ans, j-i+1);
            }

            if (j==r) {
                m[s[i]]++;
                i++;
                continue;
            }

            if (m['Q']<=t && m['W']<=t && m['E']<=t && m['R']<=t) {
                m[s[i]]++;
                i++;
            } else {
                j++;
                m[s[j]]--;
            }


        }

        return ans;
    }


    int balancedString(string s) {
        int n=s.length();
        c[0]['Q']=0;
        c[0]['W']=0;
        c[0]['E']=0;
        c[0]['R']=0;
        for (int i=0;i<n;i++) {
            c[i+1]=c[i];
            if (s[i]=='Q')
                c[i+1]['Q']++;

            if (s[i]=='W')
                c[i+1]['W']++;

            if (s[i]=='E')
                c[i+1]['E']++;

            if (s[i]=='R')
                c[i+1]['R']++;
        }
        int answer=1e5;
        for (int i=1;i<=n;i+=4)
            if (check(1,i-1)) {
                for (int j=i;j<=n+1;j+=4)
                    if (check(j,n))
                    {
                        answer=min(answer, get(i-1,j-2,s));
                        break;
                    }
            }

        return answer;
    }
};