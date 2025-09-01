class Solution {
public:
string predictPartyVictory(string senate) {
        queue<int> radiant,dire;
        int n = senate.size();
        for(int i =0; i<n; i++){
            if(senate[i]=='R') radiant.push(i);
            else
            dire.push(i);
        }
        while(!radiant.empty() && !dire.empty()){
            int r_index = radiant.front();
            radiant.pop();
            int d_index = dire.front();
            dire.pop();
        if(r_index<d_index) radiant.push(r_index+n);
        else dire.push(d_index+n);
        }
        return radiant.empty()?"Dire":"Radiant";
    }
};