class Solution {
public:
    long long dp[205][205];
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        for (auto n : prices) {
            dp[n[0]][n[1]] = n[2];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
                }
                for (int k = 1; k < i; k++) {
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
                }
            }
        }
        return dp[m][n];
    }
};
