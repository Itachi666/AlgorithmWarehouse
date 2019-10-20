class Solution {
public:
    vector<int> sum;
    
    bool guess(int mid, vector<int>& sweetness, int K) {
        int s = 0;
        for(int i = 0;i < sweetness.size();i++) {
            if(s + sweetness[i] >= mid) {
                K--;
                s = 0;
            }
            else
                s += sweetness[i];
        }
        //cout<<K<<endl;
        return K > 0;
    }
    int maximizeSweetness(vector<int>& sweetness, int K) {
        sum.push_back(0);
        for (int i=0;i<sweetness.size();i++)
            sum.push_back(sum[i]+sweetness[i]);
        
        int l=0,r=sum.back(),answer=0;
        
        while (l<r) {
            int mid=(l+r+1)/2;
            //cout<<l<<' '<<r<<endl;
            if (guess(mid, sweetness, K+1)) {
                r=mid-1;
            } else {
                l=mid;
            }
        }
            
        return l;
    }
};