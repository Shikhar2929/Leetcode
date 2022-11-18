class Solution {
public:
    long long dp[1005][1005];
    long long mod = 1223372036854775803;
    int numDistinct(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            for(int j = 0; j < t.size(); j++) {
                if (i == 0) {
                    dp[i][0] = s[0] == t[0]; 
                    break;
                }
                if (i < j)
                    break;
                if (t[j] == s[i])
                    dp[i][j] += j > 0 ? dp[i - 1][j - 1] : 1;
                dp[i][j] %= mod;
                dp[i][j] += (dp[i - 1][j] % mod);
            }
        }
        return dp[s.size() - 1][t.size() - 1];
    }
};
