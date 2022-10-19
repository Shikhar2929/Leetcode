class Solution {
public:
    int arr[20005];
    int candy(vector<int>& ratings) {
        int forward[ratings.size() + 5];
        int backward[ratings.size() + 5];
        forward[0] = 1;
        backward[ratings.size() - 1] = 1;
        int prev = ratings[0];
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > prev)
                forward[i] = forward[i-1] + 1;
            else
                forward[i] = 1;
            prev = ratings[i];
        }
        prev = ratings[ratings.size() - 1];
        for(int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > prev)
                backward[i] = backward[i + 1] + 1;
            else
                backward[i] = 1;
            prev = ratings[i];
        }
        int answer = 0;
        for(int i = 0; i < ratings.size(); i++)
            answer += max(forward[i], backward[i]);
        return answer;
    }
};
