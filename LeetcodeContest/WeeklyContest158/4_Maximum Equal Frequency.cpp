class Solution {
public:
    int count[100002]={0};
    map<int, int> m;
    
    void add(int x) {
        if (m.find(x)==m.end())
            m[x]=1;
        else
            m[x]++;
        
        if (m.find(x-1)!=m.end()) {
            m[x-1]--;
            if (m[x-1]==0) 
                m.erase(x-1);
        }
    }
    
    bool check() {
        // for (auto it:m) {
        //     cout<<it.first<<':'<<it.second<<' ';
        // }
        // cout<<endl;
        if (m.size()==1 && (m.find(1)!=m.end() || m.begin()->second==1))
            return true;
        
        if (m.size()==1)
            return false;
        
        if (m.find(1)!=m.end() && m[1]==1)
            return true;
        
        map<int, int>::iterator it = m.begin();
        if (m.find(it->first +1)!=m.end() && m[it->first +1]==1)
            return true;
        
        return false;
    }
    
    int maxEqualFreq(vector<int>& nums) {
        int n=nums.size();
        int answer=0;
        
        for (int i=0;i<n;i++) {
            count[nums[i]]++;
            
            add(count[nums[i]]);
            
            if (m.size()<=2 && check())
                answer=i+1;
        }
        
        return answer;
    }
};