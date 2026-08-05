class Solution {
public:
    TreeNode* findmin(TreeNode* root){
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Case 1: Leaf
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            else if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            else {
                TreeNode* temp = findmin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }

        return root;
    }
};