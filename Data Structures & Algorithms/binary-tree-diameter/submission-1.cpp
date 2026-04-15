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

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }

    int maxDiameter = 0; // global state to track maximum path length

    int height(TreeNode* root) 
    {
        if (root == NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Update diameter if path through this node is bigger
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return height to parent
        return 1 + max(leftHeight, rightHeight);
    }


};





