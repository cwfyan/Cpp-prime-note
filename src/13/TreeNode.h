//
// Created by wfy on 2022/12/10.
//

#ifndef SRC_TREENODE_H
#define SRC_TREENODE_H

#include "iostream"
#include "string"

class TreeNode {
public:
    TreeNode():value(""), count(){};
    TreeNode(const TreeNode &treeNode) ;

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree{
    BinStrTree();
    BinStrTree(const BinStrTree &Tree);
private:
    TreeNode *root;
};
#endif //SRC_TREENODE_H
