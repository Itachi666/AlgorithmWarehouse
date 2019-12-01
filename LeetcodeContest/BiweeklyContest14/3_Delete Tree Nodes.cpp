class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        
        vector<int> haschild(nodes+1, 0), child(nodes+1, 0);
        vector<bool> Mark(nodes+1, false);
        int ans=nodes;
        
        for (int i=0;i<nodes;i++)
            parent[i]++;
        
        for (int i=1;i<=nodes;i++)
            child[parent[i-1]]++;
        
        // for (auto c:child)
        //     if (c.second==0 && c.first!=-1 && value[c.first]==0) {
        //         parent[c.first]--;
        //         ans--;
        //         child.erase(c.first);
        //     }
        int n=nodes;
        
        while (n>1) {
            
            for (int i=2;i<=nodes;i++) {

                // cout<<i<<' '<<child[i]<<' '<<parent[i-1]<<endl;
                
                if (!Mark[i] && child[i]==0) {
                    Mark[i]=true;
                    
                    child[parent[i-1]]--;
                    
                    n--;
                    
                    
                    if (value[i-1]==0) {
                        // cout<<i<<endl;
                        ans-=haschild[i]+1;
                    } else {
                        // cout<<"123:"<<i<<endl;
                        value[parent[i-1]-1] +=  value[i-1];
                        haschild[parent[i-1]] += haschild[i]+1;                        
                    }
                }
            }
        }
        
        if (value[0]==0)
            return 0;
        
        return ans;
    }
};