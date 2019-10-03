// Runtime: 4 ms
// Memory Usage: 8.3 MB

class Solution {
public:
    int get_sum(int n)
    {
        return n*(n+1)/2;
    }
    int consecutiveNumbersSum(int N) {
        int answer=0;
        for (int i=1;N-get_sum(i-1)>0;i++)
        {
            int k=N-get_sum(i-1);
            if (k%i==0)
                answer++;
        }
        return answer;
    }
};