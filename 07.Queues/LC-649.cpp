class Solution {
public:
string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;

        // Initialize queues with indices of R and D senators
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }

        // Simulate the rounds
        while (!radiant.empty() && !dire.empty()) {
            int rIndex = radiant.front(); radiant.pop();
            int dIndex = dire.front(); dire.pop();

            // Senator with lower index bans the other
            if (rIndex < dIndex) {
                radiant.push(rIndex + n); // Goes to the end for the next round
            } else {
                dire.push(dIndex + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};