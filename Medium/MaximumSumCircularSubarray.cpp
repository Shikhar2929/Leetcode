class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int prefix_sum[30005];
        int backwards_sum[30005];
        prefix_sum[0] = nums[0];
        int c = max(nums[0], 0);
        int ca = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix_sum[i] = nums[i] + prefix_sum[i - 1];
            c += nums[i];
            ca = max(c, ca);
            c = max(c, 0);
        }
        backwards_sum[nums.size() - 1] = nums[nums.size() - 1];
        int tempsum = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            tempsum += nums[i];
            backwards_sum[i] = max(tempsum, backwards_sum[i + 1]);
        }
        int answer = prefix_sum[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            answer = max(answer, prefix_sum[i] + backwards_sum[i + 1]);   
        }
        return max(answer, ca);
    }
};
