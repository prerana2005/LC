//994
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Step 1: find all rotten oranges and count fresh ones
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        // If no fresh oranges at the start
        if(fresh == 0) return 0;
        
        int minutes = -1;
        vector<int> dir = {0,1,0,-1,0};
        
        // Step 2: BFS
        while(!q.empty()) {
            int sz = q.size();
            minutes++;
            while(sz--) {
                auto [x, y] = q.front();
                q.pop();
                for(int k=0; k<4; k++) {
                    int nx = x + dir[k], ny = y + dir[k+1];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1) {
                        grid[nx][ny] = 2;   // rot the fresh orange
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        // Step 3: check if any fresh oranges remain
        return fresh == 0 ? minutes : -1;
    }
};
