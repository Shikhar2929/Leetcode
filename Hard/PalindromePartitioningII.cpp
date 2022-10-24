class Solution {
public:
    int dp[2005];
    bool check[2005][2005];
    int minCut(string s) {
        for (int i = 1; i < s.size(); i++) {
            dp[i] = dp[i - 1] + 1;
            check[i][i] = true;
            for(int j = 0; j < i; j++) {
                if(j == i - 1 && s[j] == s[i])
                    check[j][i] = true;
                else if(j < i - 1)
                    check[j][i] = check[j + 1][i - 1] && s[j] == s[i];
                if (check[j][i]) {
                    if(j == 0) {
                        dp[i] = 0;
                        continue;
                    }
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[s.size() - 1];
    }
};
