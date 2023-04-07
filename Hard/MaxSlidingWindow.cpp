class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        multiset<int> pq;
        for (int i = 0; i < k; i++) pq.insert(nums[i]);
        answer.push_back(*pq.rbegin());
        for (int i = k; i < nums.size(); i++) {
            pq.erase(pq.find(nums[i - k]));
            pq.insert(nums[i]);
            answer.push_back(*pq.rbegin());
        }
        return answer;
    }
};
