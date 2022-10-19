class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sumEvens = 0;
        vector<int> answer;
        for(auto n: nums){
            if(n % 2 == 0)
                sumEvens += n;
        }
        
        for(auto q: queries)
        {
            int val = q[0];
            int index = q[1];
            if(val % 2 == 0){
                if(nums[index] % 2 == 0)
                    sumEvens += val;
            }
            else if(nums[index] % 2)
                sumEvens += nums[index] + val;
            else   
                sumEvens -= nums[index];
            answer.push_back(sumEvens);
            nums[index] += val;
        }
        return answer;
    }
