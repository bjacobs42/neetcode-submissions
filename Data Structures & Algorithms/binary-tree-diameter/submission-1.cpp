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
    int diameterOfBinaryTree(TreeNode* root)
    {
        std::stack<std::pair<TreeNode*, bool>> st;
        std::unordered_map<TreeNode*, int> depth;
        int longest = 0;
        
        st.emplace(root, false);
        while (st.size())
        {
            auto [node, visited] = st.top();
            st.pop();

            if (!node)
                continue;

            if (visited)
            {
                int leftDepth = node->left ? depth[node->left] : 0;
                int rightDepth = node->right ? depth[node->right] : 0;

                longest = std::max(longest, rightDepth + leftDepth);
                depth[node] = std::max(rightDepth, leftDepth) + 1;
            }
            else
            {
                st.emplace(node, true);
                st.emplace(node->left, false);
                st.emplace(node->right, false);
            }
        }
        return (longest);
    }
};
