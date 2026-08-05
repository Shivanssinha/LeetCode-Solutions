/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        int a = min(p->val, q->val);
        int b = max(p->val, q->val);
        while (1) {
            if (temp->val > a && temp->val < b) {
                return temp;
            } else if (temp->val > b) {
                temp = temp->left;
            }
            else if(temp->val <a){
                temp = temp->right;
            }
            else {
                return temp;
            }
        }
        return NULL;
    }
};