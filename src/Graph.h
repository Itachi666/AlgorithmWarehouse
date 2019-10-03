//
// Created by Niujx on 2019/9/28.
//

#include <list>
#include <vector>

#ifndef ALGORITHMWAREHOUSE_GRAPH_H
#define ALGORITHMWAREHOUSE_GRAPH_H

using namespace std;

class Graph {
    int v;
    std::list<int> *adj;
    int *indegree;
public:
    explicit Graph(int v);

    ~Graph();

    void addEdge(int x, int y);

    bool topologicalSort(std::vector<int> &sorted);
};


#endif //ALGORITHMWAREHOUSE_GRAPH_H
