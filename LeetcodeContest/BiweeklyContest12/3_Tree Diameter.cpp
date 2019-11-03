class Solution {
private:
    int v=0;
    set<int> *adj;
    int indegree[10001]={0};
    
    void addEdge(int x, int y) {
        adj[x].insert(y);
        adj[y].insert(x);
        indegree[x]++;
        indegree[y]++;
    }
    
    void delEdge(int x, int y) {
        adj[x].erase(y);
        adj[y].erase(x);
        indegree[x]--;
        indegree[y]--;
    }

public:
    int answer=0;
    
    int treeDiameter(vector<vector<int>>& edges) {
        v=edges.size()+1;
        if (v<2)
            return answer;
            
        adj = new set<int>[v];
        
        
        for (int i=0;i<v-1;i++)
            addEdge(edges[i][0], edges[i][1]);
        int num=v;
        int count=0;
        while (num>2) {
            count++;
            vector<int> s;
            for (int i=0;i<v;i++)
                if (indegree[i]==1) {
                    s.push_back(i);
                    num--;
                }
            for (auto i:s)
                delEdge(i, *adj[i].begin());
        } 
        cout<<count<<endl;
        
        return count*2+num-1;
    }
};