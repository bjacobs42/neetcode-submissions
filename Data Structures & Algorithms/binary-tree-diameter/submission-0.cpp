/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    int maxDepth(TreeNode* root, int *longestPath)
    {
        if (!root)
            return (0);
        int maxLeft = maxDepth(root->left, longestPath);
        int maxRight = maxDepth(root->right, longestPath);

        *longestPath = std::max(*longestPath, maxLeft + maxRight);
        return (std::max(maxLeft, maxRight) + 1);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        int longestPath = 0;

        maxDepth(root, &longestPath);
        return (longestPath);
    }
};
