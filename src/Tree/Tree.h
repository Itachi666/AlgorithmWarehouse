//
// Created by Niujx on 2019/10/20.
//
#include <string>
#include <vector>
#include <queue>

using namespace std;


#ifndef ALGORITHMWAREHOUSE_TREE_H
#define ALGORITHMWAREHOUSE_TREE_H

struct TreeNode {
    int val;
    TreeNode *left{};
    TreeNode *right{};

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    explicit Tree(string s);

private:
    TreeNode* root;
};

static string integerVectorToString(vector<int> list, int length = -1);

static TreeNode *stringToTreeNode(string input);

#endif //ALGORITHMWAREHOUSE_TREE_H
