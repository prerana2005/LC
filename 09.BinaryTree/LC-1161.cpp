class Solution {
public:
    map<int,int> mp;

    void dfs(TreeNode* root, int level){
        if(!root) return;
        mp[level] += root->val;
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
    int maxLevelSum(TreeNode* root) {
        mp.clear();
        dfs(root,1);

        int maxsum=INT_MIN;
        int resultlevel = 0;

        for(auto &it : mp){
            int level = it.first;
            int sum = it.second;

            if(sum>maxsum){
                maxsum = sum;
                resultlevel = level;
            }
        }
        return resultlevel;
    }
};