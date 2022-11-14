class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int answer = 0;
        int curr = 0;
        for (auto value : values) {
            answer = max(curr + value, answer);
            curr = max(curr, value);
            curr--;
        }
        return answer;
    }
};
