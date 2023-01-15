class Solution {
public:
    int dp[205][205];
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i == 0)
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                else
                    dp[i][j] = matrix[i][j] == '1' ? dp[i - 1][j] + 1 : 0;
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (dp[i][j] == 0)
                    continue;
                int curr_max = dp[i][j];
                m = max(curr_max, m);
                for (int k = j + 1; k < matrix[0].size(); k++) {
                    if (dp[i][k] >= curr_max)
                        m = max(m, curr_max * (k - j + 1));
                    else if (dp[i][k] == 0)
                        break;
                    else {
                        curr_max = dp[i][k];
                        m = max(m, curr_max * (k - j + 1));
                    }
                }
                m = max(curr_max, m);
            }
        }
        return m;
    }
};
