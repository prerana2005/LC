class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int start, int k, int n, vector<int> &path){
        if(path.size() == k && n==0){
            res.push_back(path);
            return;
        }
        if(path.size()>k || n<0){
            return;
        }
        for(int i = start; i<=9; i++){
            path.push_back(i);
            backtrack(i+1,k,n-i,path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        backtrack(1,k,n,path);
        return res;
    }
};