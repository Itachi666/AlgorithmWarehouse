class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        bool flag=true;     
        
        while (flag) {
            flag=false;
            
            int to[100]={0};
            for (int i=1;i<arr.size()-1;i++) 
            {
                if (arr[i]>arr[i-1] && arr[i]>arr[i+1]) {
                    to[i]=-1;
                    flag=true;
                    continue;
                }
            
                if (arr[i]<arr[i-1] && arr[i]<arr[i+1]) {
                    to[i]=1;
                    flag=true;
                    continue;
                }
            }
            for (int i=1;i<arr.size()-1;i++) 
            {
                arr[i]+=to[i];
                // cout<<to[i]<<' ';
            }
           
        }
        
        
        return arr;
    }
};