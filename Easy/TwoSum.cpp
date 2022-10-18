class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> a;
        for(int i=0; i<nums.size(); i++)
            a.push_back(make_pair(nums[i], i));
        sort(a.begin(), a.end());
        int i = 0;
        int j = a.size() - 1;
        while(i != j)
        {
            if(a[i].first + a[j].first > target)
                j--;
            else if(a[i].first + a[j].first < target)
                i++;
            else
                break;
        }
        vector<int> answer;
        answer.push_back(a[i].second);
        answer.push_back(a[j].second);
        return answer;
    }
};
