class Solution {
public:
    int lowBinarySearch(int low, int high, int target, vector<int> nums) {
        int mid = (low + high)/2;
        if(low == high)
        {
            if(nums[low] == target)
                return low;
            else
                return -1;
        }
        if(low + 1 == high)
        {
            if(nums[low] == target)
                return low;
            else if(nums[high] == target)
                return high;
            else
                return -1;
        }
        if(nums[mid] >= target)
            return lowBinarySearch(low, mid, target, nums);
        else
            return lowBinarySearch(mid, high, target, nums);
    }
    int highBinarySearch(int low, int high, int target, vector<int> nums) {
        int mid = (low + high)/2;
        if(low == high)
        {
            if(nums[low] == target)
                return low;
            else
                return -1;
        }
        if(low + 1 == high)
        {
            if(nums[high] == target)
                return high;
            else if(nums[low] == target)
                return low;
            else
                return -1;
        }
        if(nums[mid] > target)
            return highBinarySearch(low, mid, target, nums);
        else 
            return highBinarySearch(mid, high, target, nums);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer;
        if(nums.size() == 0)
        {
            answer.push_back(-1); answer.push_back(-1); 
            return answer;
        }
        answer.push_back(lowBinarySearch(0, nums.size() - 1, target, nums));
        answer.push_back(highBinarySearch(0, nums.size() - 1, target, nums));
        return answer;
    }
};
