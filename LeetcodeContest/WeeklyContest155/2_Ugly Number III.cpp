class Solution {
public:
    long long gy(long long x,long long y) {
        return y==0?x:gy(y,x%y);
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab=(long long)a*(long long)b/gy(a,b);
        long long ac=(long long)a*(long long)c/gy(a,c);
        long long bc=(long long)b*(long long)c/gy(b,c);
        long long abc=ab*(long long)c/gy(ab,c);

        long long l=1, r=2000000000;
        while (l<r)
        {
            long long m=(l+r)/2;
            long long tmp=m/a+m/b+m/c-m/ab-m/ac-m/bc+m/abc;
            if (tmp<n)
                l=m+1;
            else
                r=m;
        }

        return r;
    }
};