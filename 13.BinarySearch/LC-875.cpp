#include <cmath>

class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i =0; i<n; i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculatetotalhours(vector<int>& piles, int h){
        long long totalH = 0;
        int n = piles.size();

        for(int i =0; i<n; i++){
            totalH += ceil((double)piles[i]/(double)h);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = findMax(piles);
        while(l<=r){
            int mid =l+(r-l)/2;
            long long totalH = calculatetotalhours(piles,mid);
            if(totalH<=h){
                r = mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};