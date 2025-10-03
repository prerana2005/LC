class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev = nums[0];   // dp[i-1]
        int prev2 = 0;        // dp[i-2]

        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1) take += prev2;   // include current house + dp[i-2]

            int not_take = prev;        // exclude current house

            int curi = max(take, not_take);

            prev2 = prev;   // shift window
            prev = curi;
        }
        return prev;
    }
};
