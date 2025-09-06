class Solution {
    int search(TreeNode* curr, int max){
        if(!curr) return 0;

        int count = 0;
        if(curr->val >= max){
            count+=1;
            max = curr->val;
        }
        count += search(curr->left,max);
        count += search(curr->right,max);
        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        int goodnode = 1;
        goodnode += search(root->left, root->val);
        goodnode += search(root->right, root->val);
        return goodnode;
    }
};