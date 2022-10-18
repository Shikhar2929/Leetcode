class Solution {
public:
    bool checkPerfectNumber(int num) {
        int currsum = 0;
        for(int i = 1; i <= num / 2; i++) {
            if(num % i == 0)
                currsum += i;
            if(currsum > num)
                return false;
        }
        return currsum == num;
    }
};
