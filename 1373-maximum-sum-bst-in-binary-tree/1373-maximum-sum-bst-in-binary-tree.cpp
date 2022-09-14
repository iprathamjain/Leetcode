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
class NodeValue {
public:
    int maxNode, minNode, maxSum;
    bool bst;
    
    NodeValue(int minNode, int maxNode, int maxSum, bool bst) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSum = maxSum;
        this->bst = bst;
    }
};
//int minNode, int maxNode, int maxSum
class Solution {
public:
    int ans = 0;
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0,true);
        }
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.bst and right.bst and left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
        ans = max(ans,left.maxSum + right.maxSum + root->val);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), (left.maxSum + right.maxSum + root->val),true);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        ans = max(ans,max(left.maxSum,right.maxSum));
            return NodeValue(INT_MAX, INT_MIN, max(left.maxSum,right.maxSum),false);
        
    }
    public:
    int maxSumBST(TreeNode* root) {
        int a = max(largestBSTSubtreeHelper(root).maxSum,0);
        return ans;
    }
};