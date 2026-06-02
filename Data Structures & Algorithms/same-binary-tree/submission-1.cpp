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

class Solution {
public:
    void traverse (TreeNode* root1, TreeNode* root2, bool& isSame) {
        if(root1 == nullptr && root2) {
            isSame = false;
            return;
        } else if (root1 && root2 == nullptr) {
            isSame = false;
            return;
        } else if (root1 == nullptr && root2 == nullptr) {
            return;
        } else if (root1->val != root2->val) {
            isSame = false;
            return;
        }
        traverse(root1->left, root2->left, isSame);
        traverse(root1->right, root2->right, isSame);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isSame = true;
        traverse(p, q, isSame);
        return isSame;
    }
};
