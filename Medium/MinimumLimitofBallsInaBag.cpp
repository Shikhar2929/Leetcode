class Solution {
public:
    bool test(int value, vector<int> nums, int maxOperations) {
        int answer = 0;
        for (int n : nums) {
            int q = n / value * value == n ? n / value : n / value + 1;
            q--;
            answer += q;
        }
        return answer <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int a = 0;
        int low = 0;
        int high = 1e9;
        while (low < high) {
            if (low + 1 == high) {
                if (test(high, nums, maxOperations))
                    return high;
                else
                    return low;
            }
            int med = (low + high) / 2;
            bool res = test(med, nums, maxOperations);
            if (res) 
                high = med;
            else 
                low = med;
        }
        return low;
    }
};
