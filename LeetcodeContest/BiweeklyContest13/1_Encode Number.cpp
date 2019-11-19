class Solution {
public:
    string encode(int num) {
        if (num==0)
            return "";
        
        int k=2,sum=0, w=1;
        while (sum+k<num) {
            sum+=k;
            k*=2;
            w++;
        }
        
        string ans;
        cout<<sum<<' '<<k<<endl;
        
        k=num-sum-1;
        
        while (w>0) {
            if (k%2)
                ans="1"+ans;
            else
                ans="0"+ans;
            
            k/=2;
            w--;
        }
        
        return ans;
    }
};