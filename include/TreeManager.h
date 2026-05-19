#pragma once

#include "FileScanner.h"
#include "ConfigManager.h"

struct TreeNode
{
    string name;
    vector<TreeNode*> children;
};

extern TreeNode* root;

void buildTree();
void displayTree(TreeNode* node, int level = 0);