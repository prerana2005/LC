//highest altitude gain
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxalt = 0;
        int curr = 0;
        for(int i = 0; i<gain.size();i++){
            curr+=gain[i];
            maxalt = max(maxalt,curr);
        }
        return maxalt;
    }
};
