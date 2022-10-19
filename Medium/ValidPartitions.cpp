class Solution {
public:
    bool validPartition(vector<int>& nums) {
        bool dp[nums.size() + 5];
        dp[0] = true;
        dp[1] = false;
        for (int i = 2; i <= nums.size(); i++)
        {
            dp[i] = false;
            if(dp[i - 2] && nums[i-1] == nums[i-2])
            {    
                dp[i] = true;
                continue;
            }
            if(i == 2)
                continue;
            else if(dp[i-3] && nums[i-1] == nums[i-2] && nums[i-2] == nums[i-3])
                dp[i] = true;
            else if(dp[i-3] && nums[i-3] + 1 == nums[i-2] && nums[i-2] + 1 == nums[i-1])
                dp[i] = true;
        }
        return dp[nums.size()];
    }
};
