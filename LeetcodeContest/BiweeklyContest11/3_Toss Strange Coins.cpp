class Solution {
public:
    vector<int> answer;
    
    void dfs(long long n, int low, int high) {
        if (n>=low && n<=high)
            answer.push_back(n);
        
        if (n>high)
            return;
        
        int last=n%10;
        
        if (last>0)
            dfs(n*10+last-1, low, high);
        
        if (last<9)
            dfs(n*10+last+1, low, high);
    }
    
    vector<int> countSteppingNumbers(int low, int high) {
        if (low==0)
            answer.push_back(0);
        
        for (int i=1;i<10;i++)
            dfs(i,low,high);
        
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};