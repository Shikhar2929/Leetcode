class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> s;
        int i = 0; 
        int j = 1;
        s.insert(nums[i]);
        while (j < nums.size()) {
            while (j - i <= indexDiff && j < nums.size()) {
                auto it = s.upper_bound(nums[j]);
                if (it != s.end()) {
                    if ((*it - nums[j]) <= valueDiff) {
                        return true;
                    }
                }
                if (it != s.begin()) {
                    it--;
                    if (nums[j] - *(it) <= valueDiff) {
                        return true;
                    }
                }
                s.insert(nums[j]);
                j++;
            }
            if (j >= nums.size()) 
                break;
            s.erase(nums[i]);
            i++;
        }
        return false;
    }
};
