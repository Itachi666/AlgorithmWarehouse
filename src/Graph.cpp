//
// Created by Niujx on 2019/9/28.
//

#include <queue>
#include "Graph.h"

Graph::Graph(int v) {
    this->v = v;
    adj = new std::list<int>[v];

    indegree = new int[v];
    for (int i = 0; i < v; i++)
        indegree[i] = 0;
}

Graph::~Graph() {
    delete[] adj;
    delete[] indegree;
}

void Graph::addEdge(int x, int y) {
    adj[x].push_back(y);
    indegree[y]++;
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
        sortResult.push_back(t);

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
