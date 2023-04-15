class Solution {
public:
    bool test(int val, vector<vector<int>> grid) {
        int dp[grid.size() + 5][grid[0].size() + 5];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = val + grid[0][0];
                }
                else if (i == 0) {
                    if (dp[i][j - 1] <= 0) {
                        dp[i][j] = -1;
                    }
                    else dp[i][j] = grid[i][j] + dp[i][j - 1];
                }
                else if (j == 0) {
                    if (dp[i - 1][j] <= 0) {
                        dp[i][j] = -1;
                    } 
                    else dp[i][j] = grid[i][j] + dp[i - 1][j];
                }
                else {
                    if (dp[i - 1][j] <= 0 && dp[i][j - 1] <= 0) {
                        dp[i][j] = -1;
                    }
                    else if (dp[i - 1][j] <= 0) 
                        dp[i][j] = dp[i][j - 1] + grid[i][j];
                    else if (dp[i][j - 1] <= 0) 
                        dp[i][j] = dp[i - 1][j] + grid[i][j];
                    else
                        dp[i][j] = max(dp[i - 1][j],dp[i][j -1]) + grid[i][j];
                }
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1] > 0;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int l = 1;
        int h = 1000 * (dungeon.size() + dungeon[0].size() + 1) + 5;
        while (l < h) {
            int mid = (l + h) / 2;
            if (test(mid, dungeon)) {
                h = mid;
            }
            else 
                l = mid + 1;
        }
        if (test(l, dungeon)) return l;
        return h;
    }
};
