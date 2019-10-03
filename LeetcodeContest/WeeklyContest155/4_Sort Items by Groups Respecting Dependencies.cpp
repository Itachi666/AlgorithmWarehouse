class Graph {
private:
    int v;
    list<int> *adj;
    int *indegree;
    short *name2local;
    short *local2name;
public:
    explicit Graph(int v);
    ~Graph();
    void addEdge(int x,int y);
    void addPoint(int i, int x) {local2name[i]=x; name2local[x]=i;}
    bool topologicalSort(vector<int>& sorted);
};

Graph::Graph(int v) {
    this->v = v;
    adj = new std::list<int>[v];
    name2local=new short[30000];
    local2name=new short[v];

    indegree = new int[v];
    for (int i = 0; i < v; i++) {
        indegree[i] = 0;
    }
}

Graph::~Graph() {
    delete[] adj;
    delete[] indegree;
    delete[] name2local;
    delete[] local2name;
}

void Graph::addEdge(int x, int y) {
    adj[name2local[x]].push_back(name2local[y]);
    indegree[name2local[y]]++;
}

bool Graph::topologicalSort(std::vector<int> &sortResult) {
    std::queue<int> q;
    for (int i = 0; i < v; i++)
        if (!indegree[i]) {
            q.push(i);
        }
    int count = 0;

    while (!q.empty()) {
        int t = q.front();
        q.pop();
        sortResult.push_back(local2name[t]);

        count++;
        auto it = adj[t].begin();

        while (it != adj[t].end()) {
            indegree[*it]--;
            if (!indegree[*it])
                q.push(*it);
            it++;
        }
    }

    return count == v;
}


class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> answer;
        vector<int> groupList;
        int groupNum=m;
        for (int i=0;i<n;i++) 
        {
            if (group[i]==-1 && beforeItems[i].size())
            {
                group[i]=groupNum;
                groupNum++;
            }
            for (auto j:beforeItems[i])
                if (group[j]==-1)
                {
                    group[j]=groupNum;
                    groupNum++;
                }
        }
        
        vector<vector<int>> eachList(groupNum, vector<int>());
        for (int i=0;i<n;i++)
            if (group[i]>=0) {
                eachList[group[i]].push_back(i);
            }
        
        Graph G(groupNum);
        for (int i=0;i<groupNum;i++) 
            G.addPoint(i, i);
    
        for (int i=0;i<n;i++) 
            for (int j=0;j<beforeItems[i].size();j++) 
                if (group[i]!=group[beforeItems[i][j]]) {
                    G.addEdge(group[beforeItems[i][j]], group[i]);   
                }
        
        if (G.topologicalSort(groupList))
        {
            //return groupList;
            for (auto gr:groupList)
            {
                //cout<<eachList[gr].size()<<endl;
                Graph Item(eachList[gr].size());
                for (int i=0;i<eachList[gr].size();i++) 
                {
                    int t=eachList[gr][i];
                    //cout<<i<<' '<<t<<endl;
                    Item.addPoint(i,t);
                }
                for (auto i: eachList[gr]) 
                {
                    for (auto j:beforeItems[i])
                        if (group[i]==group[j])
                            Item.addEdge(j, i);
                }
                
                if (!Item.topologicalSort(answer))
                    return vector<int>();
            }
            for (int i=0;i<n;i++)
                if (group[i]==-1)
                    answer.push_back(i);
            return answer;
        }
        else
            return vector<int>();
    }
};