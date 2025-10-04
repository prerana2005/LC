class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadbuy, aheadnotbuy, curbuy, curnotbuy;
        aheadnotbuy = aheadbuy = 0;
        for(int ind = n-1; ind>=0; ind--){
            //sell
            curnotbuy = max(prices[ind]+ aheadbuy, 0+aheadnotbuy);
            //buy
            curbuy = max(-prices[ind]-fee+aheadnotbuy , 0+aheadbuy);
            aheadbuy= curbuy;
            aheadnotbuy = curnotbuy;
        }
        return aheadbuy;
    }
};