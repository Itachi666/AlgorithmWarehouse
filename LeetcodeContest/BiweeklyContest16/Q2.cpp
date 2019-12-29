class Solution {
public:
    int cal(vector<int>& arr, int t) {
        int count=0;
        for (auto i:arr)
            count+=min(t, i);
        return count;
    }
    
    int findBestValue(vector<int>& arr, int target) {
        int M=0;
        for (int i=0;i<arr.size();i++)
            M=max(M, arr[i]);
        
        int l=0, r=M;
        
        while (l<r) {
            // cout<<l<<' '<<r<<endl;
            
            if (r-l==1) {
                int t1=cal(arr, l);
                int t2=cal(arr, r);
                
                if (abs(target-t1)>abs(target-t2))
                    l=r;
                else
                    r=l;
                break;
            }
            
            int m=(l+r)/2;
            int t=cal(arr, m);
            
            if (t>=target)
                r=m;
            else
                l=m;
            
        }
        return l;
    }
};