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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0]=1;
        return dfs(root,0,targetsSum,prefix);
    }
private:
    int dfs(TreeNode* root, long long currsum, int targetsum, unordered_map<long long, int> &prefix){
        if(!root) return 0;

        currsum += root->val;
        int res = 0;

        if(prefix.count(currsum-targetsum)){
            res += prefix[currsum - targetsum];
        }

        prefix[currsum]++;

        res += dfs(root->left, currsum, targetsum,prefix);
        res += dfs(root->right, currsum, targetsum, prefix);

        prefix[currsum]--;
        return res;
    }
};