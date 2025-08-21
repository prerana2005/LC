//Kids With the Greatest Number of Candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxcandy = INT_MIN;
        for(int i =0; i<candies.size(); i++){
            if(candies[i]>maxcandy){
                maxcandy = candies[i];
            }
        }
        vector<bool>output;
        for(int i =0; i<candies.size(); i++){
            if((candies[i]+extraCandies)>=maxcandy){
                output.push_back(true);
            }
            else
            output.push_back(false);
        }
        return output;
    }
};
