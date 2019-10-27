class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> answer={0};
        if (n==0)
            return answer;
        
        // answer.push_back(1);
        // if (n==1)
        //     return answer;
        
        int num=1;
        
        for (int i=0;i<n;i++) {
            for (int j=num-1;j>=0;j--) 
                answer.push_back(answer[j] | num);
            num<<=1;
        }
        
        return answer;
    }
    
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        vector<int> t=grayCode(n);
        
        int k=0;
        while (t[k]!=start)
            k++;
        
        for (int i=k;i<t.size();i++)
            ans.push_back(t[i]);
        
        for (int i=0;i<k;i++)
            ans.push_back(t[i]);
        return ans;
    }
};