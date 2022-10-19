class Solution {
public:
    int dp[105][2];
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        int potentialAnswer = dp[nums.size() - 1][1];
        dp[0][1] = nums[0];
    
        for(int i = 1; i < nums.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return max(dp[nums.size() - 1][0], potentialAnswer);
    }
};
