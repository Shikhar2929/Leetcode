
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int answer = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1; 
            int k = nums.size() - 1;
            while(j < k){
                if(abs(nums[i] + nums[j] + nums[k] - target) < abs(target - answer) )
                    answer = nums[i] + nums[j] + nums[k];
                if(nums[i] + nums[j] + nums[k] < target)
                    j++;
                else if(nums[i] + nums[j] + nums[k] > target)
                    k--;
                else 
                    break;
            }
            if(target == answer)
                break;
        }
        return answer;
    }
};
