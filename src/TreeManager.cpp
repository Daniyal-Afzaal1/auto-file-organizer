#include "../include/TreeManager.h"

TreeNode* root = nullptr;

void buildTree()
{
    // Create root node from selected directory
    root = new TreeNode;
    root->name = Path.filename().string();

    // Loop through folders map
    for (auto pair : folders)
    {
        TreeNode* folderNode = new TreeNode;
        folderNode->name = pair.first;

        // Add subfolders if any
        for (string subfolder : pair.second)
        {
            TreeNode* childNode = new TreeNode;
            childNode->name = subfolder;

            folderNode->children.push_back(childNode);
        }

        // Attach folder to root
        root->children.push_back(folderNode);
    }
}

void displayTree(TreeNode* node, int level)
{
    if (node == nullptr)
        return;

    // indentation
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }

    cout << "|-- " << node->name << endl;

    // print children
    for (TreeNode* child : node->children)
    {
        displayTree(child, level + 1);
    }
}


