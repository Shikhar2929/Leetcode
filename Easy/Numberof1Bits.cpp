// https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0; 
        while(n > 0)
        {
            if(n & 1)
                answer++;
            n >>=1;
        }
        return answer;
    }
};
