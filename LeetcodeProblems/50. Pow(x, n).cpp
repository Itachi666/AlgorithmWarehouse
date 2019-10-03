// Runtime: 8 ms
// Memory Usage: 8.7 MB

class Solution {
public:
    double myPow(double x, int n) {
        double t = 1;
        long long k = 1;
        unordered_map<long long,double> ans;
        ans[0]=1;
        while (k/2 <= abs((long long)n)) {
            if (k==1)
                t*=x;
            else
                t *= t;
            ans[k]=t;
            k *= 2;

        }

        vector<bool> Bin;
        k = abs((long long)n);
        while (k != 0) {
            Bin.push_back(k % 2);
            k /= 2;
        }

        double answer = 1;
        k = 1;
        for (int i = 0; i < Bin.size(); i++) {
            if (Bin[i])
                answer *= ans[k];
            k *= 2;
        }
        return (n>=0)?answer:1.0/answer;
    }
};